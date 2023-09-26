#include<iostream>
#include<string>
#include<math.h>
using namespace std;

struct ponto{
    float x;
    float y;
};

float distancia(ponto ponto1, ponto ponto2);

int main()
{
    ponto a, b;
    cout << "Digite as cordenadas do ponto 'a'" << endl;
    cout << "x: ";
    cin >> a.x;
    cout << "y: ";
    cin >> a.y;
    
    cout << "Digite as cordenadas do ponto 'b'" << endl;
    cout << "x: ";
    cin >> b.x;
    cout << "y: ";
    cin >> b.y;

    cout << "A distancia do ponto 'a' ao ponto 'b' e: " << distancia(a, b) << endl;
    return 0;
}

float distancia(ponto ponto1, ponto ponto2)
{
    return sqrt(pow((ponto1.x - ponto2.x),2) + pow((ponto1.y - ponto2.y), 2));
}