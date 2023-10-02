
#ifndef PRODUTO_H
#define PRODUTO_H

#include <vector>
#include <string>


class Produto{
    private:
        std::string nome;
        double preco;
        std::string codigo;

        std::string geraCodigo(int n);

    public:
        Produto(std::string nome = "", double preco = 0);
        
        std::string getNome();
        
        double getPreco();

        std::string getCodigo();

        void setNome(std::string nome);

        void setPreco(double preco);

        void setCodigo(std::string codigo);
};

class Estoque{
    private:
        std::vector<int> qtdProdutos;
        std::vector<Produto> produtos;
    public:
        void removerProduto(std::string codigo);

        void addProduto();
        void addProduto(std::string nome, double preco, std::string codigo, int qtd);

        void addProduto(Produto produto, int qtd);

        Produto getProduto(std::string codigo);

        Produto getProduto(int index);

        int getQtdProduto(std::string codigo);

        int getQtdProdutos();

        int getQtdTotalProdutos();

        void setQtdProduto(std::string codigo, int qtd);
};

class CarrinhoDeCompras{
    private:
        Estoque estoque;
    public:
        void adicionarProduto(Produto produto, int qtdProduto);

        double calcularValorTotal();

        void removerProduto(std::string codigo);

        void removerProduto(int index);

        void removerProduto(Produto produto, int qtd);

        void esvaziarCarrinho();
};

#endif