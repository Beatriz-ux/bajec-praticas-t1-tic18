/*Crie uma classe ItemSet (conjunto de itens)
Dentro desta classe crie um vector de String 
É onde serão armazenados os
itens (cada item é um String)
IMPORTANTE! Não pode haver repetição de itens num mesmo conjunto!
Crie o método inserir(string s) que insere o item s no conjunto, caso ele não exista.
Crie o método excluir(string s) que exclui o item s do conjunto, caso ele exista.
Crie uma função main() para facilitar seus testes */
#include <iostream>
#include <vector>

using namespace std;
class ItemSet{
    private:
        vector<string> itens;
    public:
        void inserir(string s){
            for(int i = 0; i < this->itens.size(); i++){
                if(this->itens[i] == s){
                    return; //pois o item ja existe
                }
            }
            itens.push_back(s);
        }
        void excluir(string s){
            for(int i = 0; i < this->itens.size(); i++){
                if(itens[i] == s){
                    this->itens.erase(itens.begin() + i);
                    return; //acaba a operação ao apagar o item
                }
            }
        }

        void printarItens(){
            for(int i = 0; i < this->itens.size(); i++){
                cout << this->itens[i] << endl;
            }
        }

};

int main(void){
    ItemSet itemSet;
    itemSet.inserir("item1");
    itemSet.inserir("item2");

    itemSet.excluir("item1");
    itemSet.printarItens();
    return 0;
}