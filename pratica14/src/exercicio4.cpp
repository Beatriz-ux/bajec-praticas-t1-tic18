#include <iostream>

using namespace std;

void menu();
double areaQuadrado(double lado);
double perimetroQuadrado(double lado);
float areaCirculo(float raio);
float perimetroCirculo(float raio);

int main(void){
    menu();    

    return 0;
}

double areaQuadrado(double lado) {
    return lado * lado;
}

double perimetroQuadrado(double lado) {
    return 4 * lado;
}

float areaCirculo(float raio){
    return 3.14 * raio * raio;
}

float perimetroCirculo(float raio){
    return 2 * 3.14 * raio;
}

void menu(){
    int opt;
    float raio;
    double lado;

    do{
        cout << "------------MENU------------\n" << endl;
        cout << "1 - Area do circulo" << endl;
        cout << "2 - Perimetro do circulo" << endl;
        cout << "3 - Area do quadrado" << endl;
        cout << "4 - Perimetro do quadrado" << endl;
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
        case 3:
            cout << "Digite o lado do quadrado: ";
            cin >> lado;

            cout << "Area do quadrado: " << areaQuadrado(lado) << endl;
            break;
        case 4:
            cout << "Digite o lado do quadrado: ";
            cin >> lado;

            cout << "Perimetro do quadrado: " << perimetroQuadrado(lado) << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

        cout << endl;
    }while(opt != 0);
}
