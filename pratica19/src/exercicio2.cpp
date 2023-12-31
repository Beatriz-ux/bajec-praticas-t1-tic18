#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class ItemSet
{
private:
    vector<string> itens;

public:
    void inserir(string item)
    {
        for (int i = 0; i < itens.size(); ++i)
        {
            if (itens[i] == item)
            {
                cout << "Item já existe no conjunto" << endl;
                return;
            }
        }
        itens.push_back(item);
    }
    void excluir(string item)
    {
        for (int i = 0; i < itens.size(); ++i)
        {
            if (itens[i] == item)
            {
                itens.erase(itens.begin() + i);
                break;
            }
        }
    }

    bool buscar(string item)
    {
        for (int i = 0; i < itens.size(); ++i)
        {
            if (itens[i] == item)
                return true;
        }
        return false;
    }

    void printItens()
    {
        for (int i = 0; i < itens.size(); ++i)
        {
            cout << itens[i] << " ";
        }
        cout << endl;
    }

    int qntdItens()
    {
        return itens.size();
    }

    ItemSet &operator=(const ItemSet &itemSetB)
    {
        if (this == &itemSetB) // Verifica se não é a mesma instância
            return *this;

        this->itens = itemSetB.itens;

        return *this;
    }

    ItemSet operator*(ItemSet itemSetB)
    {
        ItemSet result; // conjunto resultante

        // busca cada item de A em B, se encontrar, insere no resultado
        for (string itemSetA : itens)
        {
            if (itemSetB.buscar(itemSetA))
            {
                result.inserir(itemSetA);
            }
        }
        return result;
    }

    ItemSet operator-(ItemSet itemSetB)
    {
        ItemSet result; // conjunto resultante

        // busca cada item de A em B, se nao encontrar, insere no resultado
        for (string sA : itens)
        {
            if (!itemSetB.buscar(sA))
            {
                result.inserir(sA);
            }
        }
        return result;
    }

    // nao verifica ordem apenas se os itens sao os mesmos
    bool operator==(const ItemSet &itemSetB)
    {
        // se a quantidade de itens for diferente, nao sao iguais
        if (this->itens.size() != itemSetB.itens.size())
            return false;

        // buscas cada item de B no objeto atual
        for (string sB : itemSetB.itens)
        {
            if (!buscar(sB))
                return false;
        }
        return true;
    }

    /*
    ItemSet operator<>(){
        ItemSet result; // conjunto resultante

        // busca cada item de B em C, se nao encontrar, insere no resultado
        for(string sB : itens){
            if(!buscar(sB)){
                result.inserir(sB);
            }
        }

        // busca cada item de C em B, se nao encontrar, insere no resultado
        for(string sC : itens){
            if(!buscar(sC)){
                result.inserir(sC);
            }
        }

        return result;
    }*/
    ItemSet operator+(ItemSet itemSetC)
    {
        ItemSet result;
        result = *this;
        ItemSet dif;
        dif = itemSetC - *this; // items que estão em C e não estão em B
        for (int i = 0; i < dif.itens.size(); ++i)
        {
            result.itens.push_back(dif.itens[i]);
        }
        return result;
    }
};

int main()
{

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

    cout << "\n1 - A = B" << endl;
    cout << "2 - A = B + C" << endl;
    cout << "3 - A = B * C" << endl;
    cout << "4 - A = B - C " << endl;
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
        cout << "\n(A = B + C) retorna um novo objeto ItemSet A com os itens de B e C." << endl;
        cout << "Conjuntos: " << endl;
        cout << "B: ";
        B.printItens();
        cout << "C: ";
        C.printItens();
        A = B + C;
        cout << "\nA = B + C = ";
        A.printItens();
        break;
    case 3: // A = B * C
        cout << "\n(A = B * C) retorna um novo objeto ItemSet A com os itens de B que estao em C." << endl;
        cout << "Conjuntos: " << endl;
        cout << "B: ";
        B.printItens();
        cout << "C: ";
        C.printItens();

        cout << endl;
        A = B * C;
        cout << "B * C: ";
        A.printItens();

        A = C * B;
        cout << "C * B: ";
        A.printItens();
        break;
    case 4: // A = B - C
        cout << "\n(A - B) retorna um novo objeto ItemSet com os itens de A que nao estao em B.\n";
        cout << "Conjuntos: \n";
        cout << "B: ";
        B.printItens();
        cout << "C: ";
        C.printItens();

        A = B - C;
        cout << "\nA = B - C = ";
        A.printItens();

        A = C - B;
        cout << "A = C - B = ";
        A.printItens();

        break;
    case 5: // A = B <> C
        cout << "\n(A <> B) retorna um novo objeto ItemSet com os itens de A e B que nao estao em ambos.\n";
        cout << "Conjuntos: \n";
        cout << "B: ";
        B.printItens();
        cout << "C: ";
        C.printItens();
        cout << "\nB <> C: ";
        // A = B <> C;
        //(B <> C).printItens();
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
        // comparacoes
        cout << "\nB == B: " << (B == B) << endl;
        cout << "B == C: " << (B == C) << endl;
        cout << "C == B: " << (C == B) << endl;
        cout << "C == C: " << (C == C) << endl;
        break;
    default:
        cout << "Opção inválida" << endl;
        break;
    };
    return 0;
}