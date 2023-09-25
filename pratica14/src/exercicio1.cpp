#include <iostream>

using namespace std;

double areaQuadrado(double lado);
double perimetroQuadrado(double lado);

int main(){

    double lado;

    cout << "Digite o lado do quadrado: ";
    cin >> lado;

    cout << "Area: " << areaQuadrado(lado) << endl;
    cout << "Perimetro: " << perimetroQuadrado(lado) << endl;

    return 0;
}

double areaQuadrado(double lado) {
    return lado * lado;
}

double perimetroQuadrado(double lado) {
    return 4 * lado;
}