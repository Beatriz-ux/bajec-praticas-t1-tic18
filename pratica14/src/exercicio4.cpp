#include <iostream>

using namespace std;

double areaQuadrado(double lado);
double perimetroQuadrado(double lado);

double areaQuadrado(double lado) {
    return lado * lado;
}

double perimetroQuadrado(double lado) {
    return 4 * lado;
}