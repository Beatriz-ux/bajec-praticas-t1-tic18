#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void menu(int precisao = 2);
double areaQuadrado(double lado);
double perimetroQuadrado(double lado);
float areaCirculo(float raio);
float perimetroCirculo(float raio);
float areaTriangulo(float base, float altura);
float perimetroTriangulo(float lado1, float lado2, float lado3);
void areaTrapezio();
void perimetroTrapezio();

int main(void){
    menu(3);    

    return 0;
}

double areaQuadrado(double lado) {
    return lado * lado;
}

double perimetroQuadrado(double lado) {
    return 4 * lado;
}

float areaCirculo(float raio){
    return M_PI * raio * raio;
}

float perimetroCirculo(float raio){
    return 2 * M_PI * raio;
}

float areaTriangulo(float base, float altura){
    return (base * altura) / 2;
}

float perimetroTriangulo(float lado1, float lado2, float lado3){
    return lado1 + lado2 + lado3;
}

void areaTrapezio()
{
    float bMenor, bMaior, h;
    cout << "Digite a base menor do trapezio: ";
    cin >> bMenor;
    cout << "Digite a base maior do trapezio: ";
    cin >> bMaior;
    cout << "Digite a altura do trapezio: ";
    cin >> h;

    cout << "Area do trapezio: " << ((bMenor + bMaior) * h)/2 << endl;
}

void perimetroTrapezio()
{
    float bMenor, bMaior, lado1, lado2;
    cout << "Digite a base menor do trapezio: ";
    cin >> bMenor;
    cout << "Digite a base maior do trapezio: ";
    cin >> bMaior;
    cout << "Digite o lado 1 do trapezio: ";
    cin >> lado1;
    cout << "Digite o lado 2 do trapezio: ";
    cin >> lado2;

    cout << "Perimetro do trapezio: " << (bMenor + bMaior + lado1 + lado2) << endl;
}

void menu(int precisao){
    int opt;
    float raio, lado1, lado2, lado3, altura, base;
    double lado;

    cout << fixed << setprecision(precisao);

    do{
        cout << "------------MENU------------\n" << endl;
        cout << "1 - Area do circulo" << endl;
        cout << "2 - Perimetro do circulo" << endl;
        cout << "3 - Area do quadrado" << endl;
        cout << "4 - Perimetro do quadrado" << endl;
        cout << "5 - Area do triangulo" << endl;
        cout << "6 - Perimetro do triangulo" << endl;
        cout << "7 - Area do trapezio" << endl;
        cout << "8 - Perimetro do trapezio" << endl;
        cout << "9 - Area do Hexagono" << endl;
        cout << "10 - Perimetro do Hexagono" << endl;
        cout << "0 - Sair" << endl;

        cout << "Digite uma opcao: ";
        cin >> opt;
        cout << endl;


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
        case 5:
            cout << "Digite o tamanho da base do triangulo: ";
            cin >> base;
            cout << "Digite o tamanho da altura do triangulo: ";
            cin >> altura;

            cout << "Area do triangulo: " << areaTriangulo(base, altura) << endl;
            break;
        case 6:
            cout << "Digite o lado 1 do triangulo: ";
            cin >> lado1;
            cout << "Digite o lado 2 do triangulo: ";
            cin >> lado2;
            cout << "Digite o lado 3 do triangulo: ";
            cin >> lado3;

            cout << "Perimetro do triangulo: " << perimetroTriangulo(lado1, lado2, lado3) << endl;
            break;
        case 7:
            areaTrapezio();
            break;
        case 8:
            perimetroTrapezio();
            break;
        case 9:

            cout << "Digite o lado do hexagono: ";
            cin >> lado;
            cout << "Area do Hexagono:"<<areaHexagono(lado);
            break;
        case 10:
            cout << "Digite o lado do hexagono: ";
            cin >> lado;
            cout << "Perimetro do Hexagono:"<<perimetroHexagono(lado) << endl;
            break;
        default:
            cout << "Opcao invalida!" << endl;
            break;
        }

        cout << endl;
    }while(opt != 0);
}
