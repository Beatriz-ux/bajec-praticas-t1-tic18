#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Produto{
    private:
        string nome;
        double preco;
        string codigo;

        string geraCodigo(int n){
            char cd[n+1];
            
            for(int i = 0; i < n; i++){
                cd[i] = '0' + (rand() % 10);
            }
            cd[n] = '\0';

            string codigo(cd);
            return codigo;    
        }

    public:
        Produto(string nome = "", double preco = 0){
            this->nome = nome;
            this->preco = preco;
            this->codigo = geraCodigo(10);
        }
        
        string getNome(){
            return nome;
        }
        
        double getPreco(){
            return preco;
        }

        string getCodigo(){
            return codigo;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setPreco(double preco){
            this->preco = preco;
        }

        void setCodigo(string codigo){
            this->codigo = codigo;
        }
};

class Estoque{
    private:
        vector<int> qtdProdutos;
        vector<Produto> produtos;
    public:
        Estoque(){
            qtdProdutos = vector<int>();
            produtos = vector<Produto>();
        }
        void removerProduto(string codigo){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    produtos.erase(produtos.begin() + i);
                    qtdProdutos.erase(qtdProdutos.begin() + i);
                    return;
                }
            }

            cout << "Produto não encontrado" << endl;
        }


        void addProduto(){
            Produto p;
            string nome;
            double preco;
            string codigo;
            int qtd;

            cout << "Nome: ";
            cin >> nome;
            cout << "Preço: ";
            cin >> preco;
            cout << "Código: ";
            cin >> codigo;
            cout << "Quantidade: ";
            cin >> qtd;

            p.setNome(nome);
            p.setPreco(preco);
            p.setCodigo(codigo);

            produtos.push_back(p);
            qtdProdutos.push_back(qtd);
        }


        void addProduto(string nome, double preco, string codigo, int qtd){
            Produto p;
            p.setNome(nome);
            p.setPreco(preco);
            p.setCodigo(codigo);

            produtos.push_back(p);

            qtdProdutos.push_back(qtd);
        }

        void addProduto(Produto produto, int qtd){
            produtos.push_back(produto);
            qtdProdutos.push_back(qtd);
        }
        
        // fluxo pode ser positivo ou negativo
        bool attProduto(string codigo, int fluxo){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    qtdProdutos[i] += fluxo;
                    return true;
                }
            }
            return false;
        }

        bool estoqueDisponivel(string codigo, int qtd){
            int qntdProd = getQtdProduto(codigo);
            (getQtdProduto(codigo) >= qtd && qntdProd != -1) ? true : false;
        }

        Produto getProduto(string codigo){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    return produtos[i];
                }
            }
            return Produto();
        }

        Produto getProduto(int index){
            return produtos[index];
        }

        int getQtdProduto(string codigo){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    return qtdProdutos[i];
                }
            }
            return -1;
        }

        int getQtdProduto(int index){
            return qtdProdutos[index];
        }

        int getQtdProdutos(){
            return produtos.size();
        }

        int getQtdTotalProdutos(){
            int qtdTotal = 0;
            for(int i = 0; i < qtdProdutos.size(); i++){
                qtdTotal += qtdProdutos[i];
            }
            return qtdTotal;
        }

        void setQtdProduto(string codigo, int qtd){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    qtdProdutos[i] = qtd;
                    break;
                }
            }
        }
};

class CarrinhoDeCompras{
    private:
        Estoque carrinho;
        Estoque *estoque;
    public:
        CarrinhoDeCompras(Estoque estoque){
            this->estoque = &estoque;
        };


        bool adicionarProduto(Produto produto, int qtdProduto){
            if(estoque->estoqueDisponivel(produto.getCodigo(), qtdProduto)){
                carrinho.addProduto(produto, qtdProduto);
                estoque->attProduto(produto.getCodigo(), -qtdProduto);
                return true;
            }
            return false;
        }

        double calcularValorTotal(){
            double valorTotal = 0;
            
            for(int i = 0; i < carrinho.getQtdProdutos(); i++){
                Produto p = carrinho.getProduto(i);
                int qtd = carrinho.getQtdProduto(p.getCodigo());
                valorTotal += p.getPreco() * qtd;
            }

            return valorTotal;
        }

        void removerProduto(string codigo){
            int qntd = carrinho.getQtdProduto(codigo);

            carrinho.removerProduto(codigo);
            estoque->attProduto(codigo, qntd);
        }

        void removerProduto(int index){
            int qntd = carrinho.getQtdProduto(index);
            Produto p = carrinho.getProduto(index);
            carrinho.removerProduto(p.getCodigo());
        }

        void removerProduto(Produto produto, int qtd){
            if(carrinho.getQtdProduto(produto.getCodigo()) - qtd < 0){
                cout << "Quantidade inválida" << endl;
                return;
            }
            carrinho.setQtdProduto(produto.getCodigo(), carrinho.getQtdProduto(produto.getCodigo()) - qtd);
            estoque->attProduto(produto.getCodigo(), qtd);
        }

        void esvaziarCarrinho(){
            int i;
            int tamanho = carrinho.getQtdProdutos();
            for (i = 0; i < tamanho; i++){
                carrinho.removerProduto(carrinho.getProduto(0).getCodigo());
            }
        }

        void exibirCarrinho(){
            cout << "Carrinho de Compras: " << endl;
            for(int i = 0; i < estoque.getQtdProdutos(); i++)
            {
                Produto p = estoque.getProduto(i);
                cout << "- " << p.getNome() << " (" << p.getPreco() << ") x " <<
                estoque.getQtdProduto(p.getCodigo()) << endl;
            }
        }
};

int main(){
    srand(time(0));

    // teste 1
    cout << "Teste 1" << endl;
    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);

    // adicionando produtos ao estoque
    Estoque estoque;
    estoque.addProduto(p1, 20);
    estoque.addProduto(p2, 10);
    estoque.addProduto(p3, 15);

    CarrinhoDeCompras carrinho(estoque);
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);

    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total: " << valorTotal << endl;
    cout << "\n\n";

    // teste 2
    cout << "Teste 2" << endl;
    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total apos remocao: " << valorTotal << endl;
    cout << "\n\n";

    // teste 3
    cout << "Teste 3" << endl;
    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total apos esvaziar o carrinho: " << valorTotal << endl;
    cout << "\n\n";

    // teste 4
    cout << "Teste 4" << endl;
    cout << "\n\n";
    //OBS, quando terminar o teste 4, descomenta a linha no final do codigo que tem o "p4"

    // teste 5
    carrinho.adicionarProduto(p1, 2);
    carrinho.adicionarProduto(p2, 3);
    carrinho.adicionarProduto(p3, 1);
    //carrinho.adicionarProduto(p4, 2);
    carrinho.exibirCarrinho();

    return 0;
}