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

        // insere item no conjunto, retorna true se item foi inserido
        bool inserirItem(string s){
            if(itemPertence(s))
                return false;
            else
                itens.push_back(s);
                return true;
        }

        // deleta item do conjunto, retorna true se item foi excluido
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

        // return true se item pertence ao conjunto
        bool itemPertence(string s){
            for(string item : itens){
                if(item == s)
                    return true;
            }
            return false;
        }

        // retorna indice do item no vetor, -1 se nao existir   
        int buscarItem(string s){
            for(int i = 0; i < itens.size(); i++){
                if(itens[i] == s)
                    return i;
            }
            return -1;
        }

        string printItens(){
            string s = "";
            for(string item : itens){
                s += item + " ";
            }
            return s;
        }

};

int main(){
    vector<ItemSet> sets;
    int opc, i;
    string item;

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
                // verificando se existem conjuntos
                if (sets.size() == 0){
                    cout << "Nao existem conjuntos criados!" << endl;
                    break;
                }

                // definindo indice do conjunto
                if(opc == 2){
                    cout << "Digite indice do conjunto: ";
                    cin >> i;
                    if(i < 0){
                        cout << "Indice invalido!" << endl;
                        break;
                    }
                    if(i >= sets.size()){
                        cout << "Conjunto nao existe!" << endl;
                        break;
                    }
                }else
                    i = sets.size() - 1;
                
                // inserindo item
                cout << "Digite o item a ser inserido: ";
                cin >> item;
                if(sets[i].inserirItem(item))
                    cout << "Item inserido com sucesso!" << endl;
                else
                    cout << "Item ja existe no conjunto!" << endl;
                break;
            case 3:
                // definindo indice do conjunto
                cout << "Digite o indice do conjunto: ";
                cin >> i;
                if(i < 0){
                    cout << "Indice invalido!" << endl;
                    break;
                }
                if(i >= sets.size()){
                    cout << "Conjunto nao existe!" << endl;
                    break;
                }

                // removendo item
                cout << "Digite o item a ser removido: ";
                cin >> item;
                if(sets[i].deleteItem(item))
                    cout << "Item removido com sucesso!" << endl;
                else
                    cout << "Item nao existe no conjunto!" << endl;
                break;
            case 4:
                for(int i = 0; i < sets.size(); i++){
                    cout << "Conjunto [" << i << "]: ";
                    cout << sets[i].printItens();
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