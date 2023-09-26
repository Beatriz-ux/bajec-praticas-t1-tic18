#include<iostream>
#include<string>
 using namespace std;

int fatorial(int num);

int main()
{
    int a, b, c;

    cout << "---- Calculadora de fatorial ----" << endl;
    cout << "Digite o primeiro numero: ";
    cin >> a;
    cout << "O fatorial de " << a << " e: " << fatorial(a) << endl << endl;

    cout << "Digite o segundo numero: ";
    cin >> b;
    cout << "O fatorial de " << b << " e: " << fatorial(b) << endl << endl;

    cout << "Digite o terceiro numero: ";
    cin >> c;
    cout << "O fatorial de " << c << " e: " << fatorial(c) << endl << endl;

    return 0;
}

int fatorial(int num)
{
    int total = 0;

    for(int i = 1; i <= num; i++)
    {
        total+= i;
    }
    return total;
}
