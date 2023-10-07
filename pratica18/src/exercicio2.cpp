#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:

        Ponto(int x = 0, int y = 0){
            this->x = x;
            this->y = y;
        }

        int getX(){
            return this->x;
        }

        int getY(){
            return this->y;
        }

        void setCoordenadas(int x, int y){
            this->x = x;
            this->y = y;
        }

        double calcularDistancia(){
            return sqrt(pow(this->x, 2) + pow(this->y, 2));
        }
};

int main(void){
    Ponto p1(3, 4);
    Ponto p2(-2, 7);
    Ponto p3(0, 3);
    Ponto p4(4, 0);
    Ponto pontos[3];
    Ponto p5;
    double distancia, distancia_p3, distancia_p4;

    p2.setCoordenadas(1, 1);

    cout << "Teste 1:" << endl;
    distancia = p1.calcularDistancia();
    cout << "A distância do ponto (" << p1.getX() <<", " << p1.getY() <<") até a origem é aproximadamente "<< p1.calcularDistancia() << "."  << endl;

    cout << "\nTeste 2:" << endl;
    distancia = p2.calcularDistancia();
    cout << "A distância do ponto (" << p2.getX() <<", " << p2.getY() <<") até a origem é aproximadamente " << p2.calcularDistancia() << "." << endl;


    cout << "\nTeste 3:" << endl;
    distancia_p3 = p3.calcularDistancia();
    distancia_p4 = p4.calcularDistancia();

    cout << "A distância do ponto (" << p3.getX() <<", " << p3.getY() <<") até a origem é " << p3.calcularDistancia() << " e do ponto (" << p4.getX() <<", " << p4.getY() <<") até a origem é " << p4.calcularDistancia() << "." << endl;    


    cout << "\nTeste 4:" << endl;
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    
    for (int i = 0; i < 3; ++i) {
        double distancia = pontos[i].calcularDistancia();
        cout << "Distância do ponto " << i + 1 << " até a origem: " << distancia << endl;
    }

    cout << "\nTeste 5:" << endl;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;

    return 0;
}