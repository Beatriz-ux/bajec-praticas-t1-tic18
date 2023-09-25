#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>


using namespace std;

struct Ponto{
    float x;
    float y;
};

float distancia(Ponto p1, Ponto p2);
void printPonto(Ponto p, string nome, int casasDecimais = 2);

int main(){
    Ponto p1 = {0, 0}, p2 = {1, 1};

    cout << "A distância entre ";
    printPonto(p1, "p1", 3);
    cout << " e ";
    printPonto(p2, "p2", 3);
    cout << " eh: "<< setprecision(5) <<distancia(p1, p2) << endl;
    return 0;
}

float distancia(Ponto p1, Ponto p2){
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

void printPonto(Ponto p, string nome, int casasDecimais){
    cout << fixed << setprecision(casasDecimais);
    cout << nome + "(" << p.x << ", " << p.y << ")";
}