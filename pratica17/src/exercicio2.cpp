#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:
        Ponto()
        {
            x = 0;
            y = 0;
        }

        Ponto(float x, float y)
        {
            this -> x = x;
            this -> y = y;
        }

        void setCoordenadas(float x, float y)
        {
            this -> x = x;
            this -> y = y;
        }

        float getX()
        {
            return x;
        }

        float getY()
        {
            return y;
        }

        float calcularDistancia()
        {
            return sqrt(pow((x),2) + pow((y), 2));
        }
};

int main(){
    cout << endl << endl;
    Ponto p1(3, 4);
    double distancia  = p1.calcularDistancia();
    cout << "A distancia do ponto p1 a origem e de aproximadamente: " << distancia << endl;

    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    double distancia2 = p2.calcularDistancia();
    cout << "A distancia do ponto p2 a origem e de aproximadamente: " << distancia2 << endl;

    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.calcularDistancia();
    double distancia_p4 = p4.calcularDistancia();

    cout << "A distancia do ponto p3 ate a origem e " << distancia_p3 <<
    " e do ponto p4 ate a origem e de " << distancia_p4 << endl;

    Ponto pontos[3];
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);

    for (int i = 0; i < 3; ++i) {
        double distancia_array = pontos[i].calcularDistancia();
        cout << "Distancia do ponto " << i + 1 << " ate a origem: " << distancia_array << endl;
    }

    Ponto p5;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
}