#include <iostream>

using namespace std;

int fatorial(int n){
    int fat = 1;
    for(int i = 1; i <= n; i++){
        fat *= i;
    }
    return fat;
}

int main(void){
    int n;

    cout << "Digite o primeiro numero: ";
    cin >> n;

    cout << "O fatorial de " << n << " eh " << fatorial(n) << endl;

    cout << "\nDigite o segundo numero: ";
    cin >> n;

    cout << "O fatorial de " << n << " eh " << fatorial(n) << endl;

    cout << "\nDigite o terceiro numero: ";
    cin >> n;

    cout << "O fatorial de " << n << " eh " << fatorial(n) << endl;

    return 0;
}