#include <iostream>
#include <string>

using namespace std;

class Produto{
    private:
        string nome;
        float preco;
        int codigo;
    public:
        Produto(string nome = "", float preco = 0, int codigo = 0){
            this->nome = nome;
            this->preco = preco;
            this->codigo = codigo;
        }

        float getPreco(){
            return preco;
        }
        int getCodigo(){
            return codigo;
        }
        string getNome(){
            return nome;
        }

        void setPreco(float preco){
            this->preco = preco;
        }
        void setCodigo(int codigo){
            this->codigo = codigo;
        }
        void setNome(string nome){
            this->nome = nome;
        }

};

class Estoque{
    private:
        int qtdProduto;
        Produto produto;
    public:
        Estoque(){
            qtdProduto = 0;
        }
        Estoque(Produto produto, int qtdProduto){
            this->produto = produto;
            this->qtdProduto = qtdProduto;
        }
        int getQtdProduto(){
            return qtdProduto;
        }
        Produto getProduto(){
            return produto;
        }
        void setQtdProduto(int qtdProduto){
            this->qtdProduto = qtdProduto;
        }
};

class CarrinhoDeCompras{
    private:
        Estoque estoque[10];
        int qtdProdutos;
    public:
        CarrinhoDeCompras(){
            qtdProdutos = 0;
        }
        void adicionarProduto(Produto produto, int qtdProduto){
            estoque[qtdProdutos] = Estoque(produto, qtdProduto);
            qtdProdutos++;
        }
        double calcularValorTotal(){
            double valorTotal = 0;
            for(int i = 0; i < qtdProdutos; i++){
                valorTotal += estoque[i].getProduto().getPreco() * estoque[i].getQtdProduto();
            }
            return valorTotal;
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

    return 0;
}