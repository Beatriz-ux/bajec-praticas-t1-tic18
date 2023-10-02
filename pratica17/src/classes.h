#include <iostream>
#include <string>

using namespace std;

class Produto{
    private:
        string nome;
        double preco;
    public:
        Produto();
        Produto(string nome, double preco);
        double getPreco();
};

class Estoque{
    private:
        int qtdProduto;
        Produto produto;
    public:
        Estoque();
        Estoque(Produto produto, int qtdProduto);
        int getQtdProduto();
        Produto getProduto();
        void setQtdProduto(int qtdProduto);
};

class CarrinhoDeCompras{
    private:
        Estoque estoque[10];
        int qtdProdutos;
    public:
        CarrinhoDeCompras();
        void adicionarProduto(Produto produto, int qtdProduto);
        double calcularValorTotal();
};