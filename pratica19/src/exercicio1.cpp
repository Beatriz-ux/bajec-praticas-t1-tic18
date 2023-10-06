#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

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

        ItemSet operator=(ItemSet &itemSet){
            this->itens = itemSet.itens;
            return *this;
        }

        ItemSet operator*(ItemSet itemSetB){
            ItemSet result; // conjunto resultante

            // busca cada item de A em B, se encontrar, insere no resultado
            for(string itemSetA : itens){
                if(itemSetB.buscar(itemSetA)){
                    result.inserir(itemSetA);
                }
            }
            return result;
        }

        ItemSet operator-(ItemSet itemSetB){
            ItemSet result; // conjunto resultante

            // busca cada item de A em B, se nao encontrar, insere no resultado
            for(string sA : itens){
                if(!itemSetB.buscar(sA)){
                    result.inserir(sA);
                }
            }
            return result;
        }

        // nao verifica ordem apenas se os itens sao os mesmos
        bool operator==(const ItemSet &itemSetB){
            // se a quantidade de itens for diferente, nao sao iguais
            if(this->itens.size() != itemSetB.itens.size())
                return false;

            // buscas cada item de B no objeto atual
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
    ItemSet D;
    ItemSet E;
    
    B.inserir("item1");
    B.inserir("item2");
    B.inserir("item3");

    C.inserir("item2");
    C.inserir("item3");
    C.inserir("item4");

    D.inserir("item2");
    D.inserir("item1");

    E.inserir("item1");
    E.inserir("item3");
    E.inserir("item2");


    cout << "\n1 - A = B" << endl;
    cout << "2 - A = B + C" << endl;
    cout << "3 - A = B * C" << endl;
    cout << "4 - Operador - " << endl;
    cout << "5 - A = B <> C" << endl;
    cout << "6 - Operador == " << endl;
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
            cout << "\n(A = B * C) retorna um novo objeto ItemSet A com os itens de B que estao em C." << endl;
            cout << "Conjuntos: " << endl;
            cout << "B: ";
            B.printItens();
            cout << "C: ";
            C.printItens();
            
            cout << endl;
            cout << "B * C: ";
            (B * C).printItens();
            cout << "C * B: ";
            (C * B).printItens();
            break;
        case 4: // A = B - C
            cout << "\n(A - B) retorna um novo objeto ItemSet com os itens de A que nao estao em B.\n";
            cout << "Conjuntos: \n";
            cout << "B: ";
            B.printItens();
            cout << "C: ";
            C.printItens();
            cout << "\nB - C: ";
            //A = B - C;
            (B - C).printItens();
            cout << "C - B: ";
            //A = C - D;
            (C - B).printItens();
            break;
        case 5: // A = B <> C
            break;
        case 6: // A = B == C
            cout << boolalpha;
            cout << "\n(A == B) retorna true se os itens de A forem iguais aos itens de B. Nao verifica ordem de itens.\n";
            
            // prints dos conjuntos
            cout << "Conjuntos: \n";
            cout << "B: ";
            B.printItens();
            cout << "C: ";
            C.printItens();
            cout << "D: ";
            D.printItens();
            cout << "E: ";
            E.printItens();

            // comparacoes
            cout << "\nB == B: " << (B == B) << endl;
            cout << "B == C: " << (B == C) << endl;
            cout << "C == B: " << (C == B) << endl;
            cout << "B == D: " << (B == D) << endl;
            cout << "D == B: " << (D == B) << endl;
            cout << "B == E: " << (B == E) << endl;
            cout << "E == B: " << (E == B) << endl;
            break;
        default:
            cout << "Opção inválida" << endl;
            break;
    };
    return 0;
}