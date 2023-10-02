#include "classes.h"

Produto::Produto(){
    nome = "";
    preco = 0;
}

Produto::Produto(string nome, double preco){
    this->nome = nome;
    this->preco = preco;
}

double Produto::getPreco(){
    return preco;
}

Estoque::Estoque(){
    qtdProduto = 0;
}

Estoque::Estoque(Produto produto, int qtdProduto){
    this->produto = produto;
    this->qtdProduto = qtdProduto;
}

int Estoque::getQtdProduto(){
    return qtdProduto;
}

Produto Estoque::getProduto(){
    return produto;
}

void Estoque::setQtdProduto(int qtdProduto){
    this->qtdProduto = qtdProduto;
}

CarrinhoDeCompras::CarrinhoDeCompras(){
    qtdProdutos = 0;
}

void CarrinhoDeCompras::adicionarProduto(Produto produto, int qtdProduto){
    estoque[qtdProdutos] = Estoque(produto, qtdProduto);
    qtdProdutos++;
}

double CarrinhoDeCompras::calcularValorTotal(){
    double valorTotal = 0;
    for(int i = 0; i < qtdProdutos; i++){
        valorTotal += estoque[i].getProduto().getPreco() * estoque[i].getQtdProduto();
    }
    return valorTotal;
}