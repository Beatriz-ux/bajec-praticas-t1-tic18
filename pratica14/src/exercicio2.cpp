#include<iostream>
#include<string>
using namespace std;

float converter(float temp);
void entrada_saida();

int main()
{
    cout << "---- Conversor de Celsius para Fahrenheit ----" << endl;
    entrada_saida();

    return 0;
}

float converter(float temp)
{
    return (temp * 1.8) + 32;
}

void entrada_saida()
{
    float temperatura;
    cout << "Insira a temperatura desejada em Celsius: ";
    cin >> temperatura;

    cout << temperatura << " graus Celsius e igual a: " 
    << converter(temperatura) << " graus Fahrenheit";
}