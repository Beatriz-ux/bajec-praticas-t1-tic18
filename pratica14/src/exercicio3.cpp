#include <iostream>
#include <cmath>

using namespace std;

struct Ponto{
    float x;
    float y;
};

float distancia(Ponto p1, Ponto p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main(void){
    Ponto p1, p2;

    p1.x = 0;
    p1.y = 0;
    p2.x = 10;
    p2.y = 5;

    cout << "A distancia entre os pontos ("<< p1.x << ", " << p1.y << ") e (" << p2.x << ", " << p2.y << ") eh " << distancia(p1, p2) << endl;
    cout << endl;

    cout << "Digite as coordenadas do primeiro ponto (x, y): ";
    cin >> p1.x >> p1.y;

    cout << "Digite as coordenadas do segundo ponto (x, y): ";
    cin >> p2.x >> p2.y;

    cout << "A distancia entre os pontos eh " << distancia(p1, p2) << endl;

    return 0;
}