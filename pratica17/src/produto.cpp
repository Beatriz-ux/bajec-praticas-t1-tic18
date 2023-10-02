#include "Produto.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// produto
Produto::Produto(string nome, double preco){
    this->nome = nome;
    this->preco = preco;
    this->codigo = geraCodigo(10);
}

string Produto::geraCodigo(int n){
    char cd[n+1];
    
    for(int i = 0; i < n; i++){
        cd[i] = '0' + (rand() % 10);
    }
    cd[n] = '\0';

    string codigo(cd);
    return codigo;    
}
string Produto::getNome(){
    return nome;
}
double Produto::getPreco(){
    return preco;
}
string Produto::getCodigo(){
    return codigo;
}
void Produto::setNome(string nome){
    this->nome = nome;
}
void Produto::setPreco(double preco){
    this->preco = preco;
}
void Produto::setCodigo(string codigo){
    this->codigo = codigo;
}

// estoque
void Estoque::removerProduto(string codigo){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].getCodigo() == codigo){
            produtos.erase(produtos.begin() + i);
            qtdProdutos.erase(qtdProdutos.begin() + i);
            return;
        }
    }

    cout << "Produto não encontrado" << endl;
}

void Estoque::addProduto(){
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
void Estoque::addProduto(string nome, double preco, string codigo, int qtd){
    Produto p;
    p.setNome(nome);
    p.setPreco(preco);
    p.setCodigo(codigo);

    produtos.push_back(p);

    qtdProdutos.push_back(qtd);
}

void Estoque::addProduto(Produto produto, int qtd){
    produtos.push_back(produto);
    qtdProdutos.push_back(qtd);   
}

Produto Estoque::getProduto(string codigo){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].getCodigo() == codigo){
            return produtos[i];
        }
    }
    return Produto();
}

Produto Estoque::getProduto(int index){
    return produtos[index];
}

int Estoque::getQtdProduto(string codigo){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].getCodigo() == codigo){
            return qtdProdutos[i];
        }
    }
    return -1; 
}

int Estoque::getQtdProdutos(){
    return produtos.size();
}

int Estoque::getQtdTotalProdutos(){
    int qtdTotal = 0;
    for(int i = 0; i < qtdProdutos.size(); i++){
        qtdTotal += qtdProdutos[i];
    }
    return qtdTotal;
}

void Estoque::setQtdProduto(string codigo, int qtd){
    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].getCodigo() == codigo){
            qtdProdutos[i] = qtd;
            break;
        }
    }
}

// carrinho de compras
void CarrinhoDeCompras::adicionarProduto(Produto produto, int qtdProduto){
    estoque.addProduto(produto, qtdProduto);
}

double CarrinhoDeCompras::calcularValorTotal(){
    double valorTotal = 0;
    
    for(int i = 0; i < estoque.getQtdProdutos(); i++){
        Produto p = estoque.getProduto(i);
        int qtd = estoque.getQtdProduto(p.getCodigo());
        valorTotal += p.getPreco() * qtd;
    }

    return valorTotal;
}

void CarrinhoDeCompras::removerProduto(string codigo){
    estoque.removerProduto(codigo);
}

void CarrinhoDeCompras::removerProduto(int index){
    Produto p = estoque.getProduto(index);
    estoque.removerProduto(p.getCodigo());
}

void CarrinhoDeCompras::removerProduto(Produto produto, int qtd){
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

void CarrinhoDeCompras::esvaziarCarrinho(){
    int i;
    int tamanho = estoque.getQtdProdutos();
    for (i = 0; i < tamanho; i++){
        estoque.removerProduto(estoque.getProduto(0).getCodigo());
    }
}
