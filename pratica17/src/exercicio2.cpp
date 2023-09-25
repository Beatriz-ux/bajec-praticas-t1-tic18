#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

class Ponto{
    private:
        double x;
        double y;
    public:
        Ponto(double _x = 0, double _y = 0){
            x = _x;
            y = _y;
        }

        double getX(){
            return x;
        }
        double getY(){
            return y;
        }

        void setX(double _x){
            x = _x;
        }
        void setY(double _y){
            y = _y;
        }
        void setCoordenadas(double _x, double _y){
            this->setX(_x);
            this->setY(_y);
        }

        double distancia(){
            return sqrt(pow(x, 2) + pow(y, 2));
        }

        string toString(){
            return toString(3);
        }
        string toString(int casasDecimais){
            string strX = to_string(x);
            string strY = to_string(y);
            strX = strX.substr(0, strX.find(".") + casasDecimais + 1);
            strY = strY.substr(0, strY.find(".") + casasDecimais + 1);

            return "(" + strX + ", " + strY + ")";
        }
        string toString(string nome, int casasDecimais){
            return nome + toString(casasDecimais);
        }
        string toString(string nome){
            return toString(nome, 3);
        }
};

int main(){
    int precisao = 2;
    cout << fixed << setprecision(precisao);

    // teste 1
    Ponto p1(3, 4);
    double distancia = p1.distancia();
    cout << "Distancia " + p1.toString("p1", precisao) + " pra origem: " << distancia;
    
    // teste 2
    Ponto p2(-2, 7);
    p2.setCoordenadas(1, 1);
    distancia = p2.distancia();
    cout << "\n\nDistancia " + p2.toString("p2", precisao) + " pra origem: " << distancia;

    // teste 3
    Ponto p3(0, 3);
    Ponto p4(4, 0);
    double distancia_p3 = p3.distancia();
    double distancia_p4 = p4.distancia();
    cout << "\n\nDistancia " + p3.toString("p3", precisao) + " pra origem: " << distancia_p3;
    cout << " e distancia " + p4.toString("p4", precisao) + " pra origem: " << distancia_p4 << endl;

    return 0;
}