#include <iostream>

using namespace std;

float celsiusParaFahrenheit(float celsius){
    return (celsius * 9/5) + 32;
}

void printCelsiusParaFahrenheit(float celsius){
    cout << celsius << " graus Celsius equivalem a " << celsiusParaFahrenheit(celsius) << " graus Fahrenheit." << endl;
}

void conversorCelsiusParaFahrenheit(){
    float celsius;
    cout << "Digite a temperatura em graus Celsius: ";
    cin >> celsius;
    printCelsiusParaFahrenheit(celsius);
}


int main(void){
    printCelsiusParaFahrenheit(0);
    printCelsiusParaFahrenheit(100);

    cout << endl;
    conversorCelsiusParaFahrenheit();

    return 0;
}