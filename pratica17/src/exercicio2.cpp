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

    Ponto p1(3, 4);
    double distancia = p1.distancia();


    cout << "Distancia " + p1.toString("p1", precisao) + " pra origem: " << distancia << endl;
    return 0;
}