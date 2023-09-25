#include <iostream>

using namespace std;



void convertCtoF();
float CtoF(float c);

int main(){
    convertCtoF();

    return 0;
}

float CtoF(float c){
    return (c * 9/5) + 32;
}

void convertCtoF(){
    float c;
    cout << "Digite a temperatura em Celsius: ";
    cin >> c;
    cout << "A temperatura em Fahrenheit é: " << CtoF(c) << endl;
}