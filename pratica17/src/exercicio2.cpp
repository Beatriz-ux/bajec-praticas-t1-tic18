#include <iostream>
#include <cmath>

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

        double distancia(Ponto p){
            return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
        }

        string toString(){
            return to_string(3);
        }
        string toString(int casasDecimais){
            double aux = pow(10, casasDecimais);
            string strX = to_string(round(x * aux) / aux);
            string strY = to_string(round(y * aux) / aux);

            return "(" + strX + ", " + strY + ")";
        }
};

int main(){
    Ponto p1(3, 4);

    return 0;
}