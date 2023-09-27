#include <iostream>
#include <string>
#include <vector>

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
        void removerProduto(string codigo){
            for(int i = 0; i < produtos.size(); i++){
                if(produtos[i].getCodigo() == codigo){
                    produtos.erase(produtos.begin() + i);
                    qtdProdutos.erase(qtdProdutos.begin() + i);
                    break;
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
        Estoque estoque;
    public:
        void adicionarProduto(Produto produto, int qtdProduto){
            estoque.addProduto(produto, qtdProduto);
        }

        double calcularValorTotal(){
            double valorTotal = 0;
            
            for(int i = 0; i < estoque.getQtdProdutos(); i++){
                Produto p = estoque.getProduto(i);
                int qtd = estoque.getQtdProduto(p.getCodigo());
                valorTotal += p.getPreco() * qtd;
            }

            return valorTotal;
        }

        void removerProduto(string codigo){
            estoque.removerProduto(codigo);
        }

        void removerProduto(int index){
            Produto p = estoque.getProduto(index);
            estoque.removerProduto(p.getCodigo());
        }

        void removerProduto(Produto produto, int qtd){
            if(estoque.getQtdProduto(produto.getCodigo()) - qtd < 0){
                cout << "Quantidade inválida" << endl;
                return;
            }
            else if(estoque.getQtdProduto(produto.getCodigo()) - qtd == 0){
                estoque.removerProduto(produto.getCodigo());
                return;
            }

            estoque.setQtdProduto(produto.getCodigo(), estoque.getQtdProduto(produto.getCodigo()) - qtd);
        }
};

int main(){

    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);

    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total: " << valorTotal << endl;

    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total apos remocao: " << valorTotal << endl;

    return 0;
}