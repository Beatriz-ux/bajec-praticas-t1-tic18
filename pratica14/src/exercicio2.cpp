#include <iostream>
#include <iomanip>
using namespace std;

double converteParaCelcius(double fahrenheit);
double converteParaFahrenheit(double celcius);
void conversorCelciusFahrenheit(double celcius);
void conversorFahrenheitCelcius(double fahrenheit);
void entradaTemperatura();

int main(void)
{
    cout<<fixed;
    cout<<setprecision(2);
    entradaTemperatura();
    return 0;
}
double converteParaCelcius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}
double converteParaFahrenheit(double celcius)
{
    return celcius * 9 / 5 + 32;
}

void conversorCelciusFahrenheit(double celcius)
{
    cout << celcius << " graus Celcius equivalem a " << converteParaFahrenheit(celcius) << " graus Fahrenheit" << endl;
}
void conversorFahrenheitCelcius(double fahrenheit)
{
    cout << fahrenheit << " graus Fahrenheit equivalem a " << converteParaCelcius(fahrenheit) << " graus Celcius" << endl;
}
void entradaTemperatura()
{
    double temperatura;
    int opcao;
    cout << "[1] para converter de Celcius para Fahrenheit" << endl;
    cout << "[2] para converter de Fahrenheit para Celcius: ";
    cin >> opcao;
    if (opcao == 1)
    {
        cout << "Digite uma temperatura: ";
        cin >> temperatura;
        conversorCelciusFahrenheit(temperatura);
    }
    else if (opcao == 2)
    {
        cout << "Digite uma temperatura: ";
        cin >> temperatura;
        conversorFahrenheitCelcius(temperatura);
    }
    else
    {
        cout << "Opcao invalida!" << endl;
    }
}