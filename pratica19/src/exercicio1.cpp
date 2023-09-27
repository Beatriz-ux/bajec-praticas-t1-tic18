#include <iostream>
#include <vector>
#include <string>

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

        ItemSet operator=(ItemSet &itemSet){
            this->itens = itemSet.itens;
            return *this;
        }

        ItemSet operator-(ItemSet itemSetB){
            ItemSet result;

            for(string sB : itemSetB.itens){
                if(!buscar(sB))
                    result.inserir(sB);
            }

            return result;
        }

        bool operator==(ItemSet itemSetB){
            if(this->itens.size() != itemSetB.itens.size())
                return false;

            for(string sB : itemSetB.itens){
                if(!buscar(sB))
                    return false;
            }
            return true;
            
        }
};

int main(){

    int opcao;
    ItemSet A;
    ItemSet B;
    ItemSet C;
    
    B.inserir("item1");
    B.inserir("item2");
    B.inserir("item3");

    C.inserir("item2");
    C.inserir("item3");


    cout << "\n1 - A = B" << endl;
    cout << "2 - A = B + C" << endl;
    cout << "3 - A = B * C" << endl;
    cout << "4 - A = B - C" << endl;
    cout << "5 - A = B <> C" << endl;
    cout << "6 - B == C" << endl;
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
            cout << "B: ";
            B.printItens();
            cout << "C: ";
            C.printItens();
            //A = B - C;
            cout << "A: ";
            (B-C).printItens();
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