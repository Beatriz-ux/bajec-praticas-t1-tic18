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
        ItemSet operator=(ItemSet &itemSet){
            this->itens = itemSet.itens;
            return *this;
        }
};

int main(){

    int opcao;
    ItemSet A;
    ItemSet B;
    ItemSet C;
    
    B.inserir("item1");
    B.inserir("item2");



    cout << "\n1 - A = B" << endl;
    cout << "2 - A = B + C" << endl;
    cout << "3 - A = B * C" << endl;
    cout << "4 - A = B - C" << endl;
    cout << "5 - A = B <> C" << endl;
    cout << "6 - A = B == C" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao)
    {
        case 0:
            break;
        case 1: // A = B
            cout << "B: ";
            B.printItens();
            
            A = B;
            cout << "A: ";
            A.printItens();
            break;
        case 2: // A = B + C
            break;
        case 3: // A = B * C
            break;
        case 4: // A = B - C
            break;
        case 5: // A = B <> C
            break;
        case 6: // A = B == C
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
    };
    return 0;
}