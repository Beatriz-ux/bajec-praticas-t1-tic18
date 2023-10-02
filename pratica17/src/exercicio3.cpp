#include <iostream>
#include <string>
#include <vector>
#include "Produto.h"

using namespace std;


int main(){
    srand(time(NULL));


    // teste 1
    cout << "Teste 1" << endl;
    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);

    CarrinhoDeCompras carrinho;
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
    cout << "Valor total após esvaziar o carrinho: " << valorTotal << endl;
    cout << "\n\n";

    // teste 4
    cout << "Teste 4" << endl;
    cout << "\n\n";

    // teste 5
    cout << "Teste 5" << endl;
    cout << "\n\n";

    return 0;
}