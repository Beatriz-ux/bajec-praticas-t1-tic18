#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    private:
        double x, y;
    public:
        Ponto(double x=0, double y=0){
            this->x = x;
            this->y = y;
        };
        double getX(){
            return this->x;
        };
        double getY(){
            return this->y;
        };
        void setX(double x){
            this->x = x;
        };
        void setY(double y){
            this->y = y;
        };
        void setXY(double x, double y){
            this->x = x;
            this->y = y;
        };
        double distancia(){
            return sqrt(pow(this->x, 2) + pow(this->y, 2));
        };


};

int main(void){
    //exemplo 1
    Ponto ponto(3, 4);
    cout << "A distancia do ponto (" << ponto.getX() << ", " << ponto.getY() << ") ate a origem eh aproximadamente: " << ponto.distancia() << endl;
    cout <<endl;
    
    //exemplo 2
    Ponto p2(-2, 7);
    p2.setXY(1, 1);
    cout << "A distancia do ponto (" << p2.getX() << ", " << p2.getY() << ") ate a origem eh aproximadamente: " << p2.distancia() << endl;
    cout <<endl;
    
    //exemplo 3
    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.distancia();
    double distancia_p4 = p4.distancia();
    cout << "A distancia do ponto (" << p3.getX() << ", " << p3.getY() << ") ate a origem eh " << distancia_p3<<
    " e do ponto (" << p4.getX() << ", " << p4.getY() << ") ate a origem é " << distancia_p4<< endl;
    cout <<endl;
    //exemplo 4
    Ponto pontos[3];
    pontos[0].setXY(2, 2);
    pontos[1].setXY(-1, 5);
    pontos[2].setXY(0, 0);

    for(int i=0 ; i<3 ; i++){
        double distancia = pontos[i].distancia();
        cout << "A distancia do ponto (" << pontos[i].getX() << ", " << pontos[i].getY() << ") ate a origem eh " << distancia << endl;
    }

    //exemplo 5
    Ponto p5;
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    p5.setXY(8,-3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")" << endl;
    return 0;
}