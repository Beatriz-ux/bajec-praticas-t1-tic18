#include <iostream>
using namespace std;

int calculaFatoria(int numero);
void fatorial(int numero);



int main(void){
    int numero;
    cout << "Digite um numero: ";
    cin >> numero;
    fatorial(numero);

    return 0;
}

int calculaFatoria(int numero){
    int fatorial = 1;
    for(int i = 2; i <= numero; i++){
        fatorial *= i;
    }
    return fatorial;
}
void fatorial(int numero){
    cout << "Fatorial de " << numero << "! = " << calculaFatoria(numero) << endl;
}