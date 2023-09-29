#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
        ItemSet(){
            itens = vector<string>();
        }
        ItemSet(vector<string> itens){
            this->itens = itens;
        }

        vector<string> getItens(){
            return itens;
        }
        void setItens(vector<string> itens){
            this->itens = itens;
        }

        bool inserirItem(string s){
            for(string item : itens){
                if(item == s)
                    return false;
            }
            itens.push_back(s);
            return true;
        }

        bool deleteItem(string s){
            int i;
            for(i = 0; i < itens.size(); i++){
                if(itens[i] == s){
                    itens.erase(itens.begin() + i);
                    return true;
                }
            }
            return false;
        }

};

int main(){
    vector<ItemSet> sets;
    int opc, i;

    do{
        cout << "1 - Criar novo conjunto" << endl;
        cout << "2 - Inserir item em conjunto" << endl;
        cout << "3 - Remover item de conjunto" << endl;
        cout << "4 - Listar conjuntos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite a opcao desejada: ";
        cin >> opc;

        switch(opc){
            case 0:
                break;
            case 1:
                sets.push_back(ItemSet());
            case 2:
                int i;
                string item;
                cout << "Digite o item a ser inserido: ";
                cin >> item;
                cout << "Digite o indice do conjunto: ";
                cin >> i;
                if(i >= 0 && i < sets.size()){
                    if(sets[i].inserirItem(item))
                        cout << "Item inserido com sucesso!" << endl;
                    else
                        cout << "Item ja existe no conjunto!" << endl;
                }else{
                    cout << "Indice invalido!" << endl;
                }
                break;
            case 3:
                int j;
                string item2;
                cout << "Digite o item a ser removido: ";
                cin >> item2;
                cout << "Digite o indice do conjunto: ";
                cin >> j;
                if(j >= 0 && j < sets.size()){
                    if(sets[j].deleteItem(item2))
                        cout << "Item removido com sucesso!" << endl;
                    else
                        cout << "Item nao existe no conjunto!" << endl;
                }else{
                    cout << "Indice invalido!" << endl;
                }
                break;
            case 4:
                for(int i = 0; i < sets.size(); i++){
                    cout << "Conjunto " << i << ": ";
                    for(string item : sets[i].getItens()){
                        cout << item << " ";
                    }
                    cout << endl;
                }
                break;
            default:
                cout << "Opcao invalida!" << endl;
                break;
        }

    }while(opc != 0);






    return 0;
}