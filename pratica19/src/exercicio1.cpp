#include <iostream>
#include <vector>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
        ItemSet(){
            itens = vector<string>();
        }
        ItemSet(ItemSet &itemSet){
            itens = itemSet.itens;
        }
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
        void printItens(){
            for(int i = 0; i < itens.size(); ++i){
                cout << itens[i] << " ";
            }
            cout << endl;
        }
};

int main(){

    int opcao;
    ItemSet A;
    
    A.inserir("item1");
    A.inserir("item2");

    cout << "A: ";
    A.printItens();

    cout << "Insira sua operação: " << endl;
    cout << "1 - A = B" << endl;
    cout << "2 - A = B + C" << endl;
    cout << "3 - A = B * C" << endl;
    cout << "4 - A = B - C" << endl;
    cout << "5 - A = B <> C" << endl;
    cout << "6 - A = B == C" << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 1:
        ItemSet B(A);
        cout << "B: ";
        B.printItens();
        break;
    };

    return 0;
}