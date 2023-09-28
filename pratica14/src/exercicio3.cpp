#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

typedef struct{
    int coordX;
    int coordY;
}Ponto;
void calcularDistancia(Ponto ponto1, Ponto ponto2);


int main(void){
    Ponto ponto1, ponto2;
    cout<<fixed;
    cout<<setprecision(2);
    cout << "Digite as coordenadas do ponto 1: ";
    cin >> ponto1.coordX >> ponto1.coordY;
    cout << "Digite as coordenadas do ponto 2: ";
    cin >> ponto2.coordX >> ponto2.coordY;
    calcularDistancia(ponto1, ponto2);
    return 0;
}
void calcularDistancia(Ponto ponto1, Ponto ponto2){
    cout << "Distancia entre os pontos: " << sqrt(pow(ponto2.coordX - ponto1.coordX, 2) + pow(ponto2.coordY - ponto1.coordY, 2)) << endl;
}