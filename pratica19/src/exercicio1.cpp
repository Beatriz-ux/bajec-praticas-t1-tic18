#include <bits/stdc++.h>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
        void inserir(string item){
            for(int i = 0; i < itens.size(); ++i){
                if(itens[i] == item){
                    cout << "Item já existe no conjunto" << endl;
                    return;
                }
            }
            itens.push_back(item);
        }
        void excluir(string item){
            for(int i = 0; i < itens.size(); ++i){
                if(itens[i] == item){
                    itens.erase(itens.begin() + i);
                    break;
                }
            }
        }

        bool buscar(string item){
            for(int i = 0; i < itens.size(); ++i){
                if(itens[i] == item)
                    return true;
            }
            return false;
        }

        void printItens(){
            for(int i = 0; i < itens.size(); ++i){
                cout << itens[i] << " ";
            }
            cout << endl;
        }

        int qntdItens(){
            return itens.size();
        }
};

int main(void){
    ItemSet itemSetA;

    itemSetA.inserir("item1");
    itemSetA.inserir("item2");
    itemSetA.inserir("item3");
    itemSetA.inserir("item4");
    itemSetA.inserir("item5");
    
    cout << "Quantidade de itens em A: " << itemSetA.qntdItens() << endl;
    cout << "Itens: " << endl;
    itemSetA.printItens();
    itemSetA.excluir("item3");
    itemSetA.excluir("item4");
    
    cout << "Quantidade de itens em A: " << itemSetA.qntdItens() << endl;
    cout << "Itens: " << endl;
    itemSetA.printItens();

    return 0;
}