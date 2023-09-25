#include <iostream>

using namespace std;

float areaCirculo(float raio){
    return 3.14 * raio * raio;
}

float perimetroCirculo(float raio){
    return 2 * 3.14 * raio;
}

void menu(){
    int opt;
    float raio;

    do{
        cout << "------------MENU------------\n" << endl;
        cout << "1 - Area do circulo" << endl;
        cout << "2 - Perimetro do circulo" << endl;
        cout << "0 - Sair" << endl;

        cout << "Digite uma opcao: ";
        cin >> opt;

        switch (opt){
        case 0:
            cout << "Saindo..." << endl;
            break;
        case 1:
            cout << "Digite o raio do circulo: ";
            cin >> raio;

            cout << "Area do circulo: " << areaCirculo(raio) << endl;
            break;
        case 2:
            cout << "Digite o raio do circulo: ";
            cin >> raio;
            
            cout << "Perimetro do circulo: " << perimetroCirculo(raio) << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

        cout << endl;
    }while(opt != 0);
}

int main(void){
    menu();    

    return 0;
}