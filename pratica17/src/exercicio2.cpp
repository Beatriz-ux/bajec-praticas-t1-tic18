#include <iostream>
#include <cmath>

using namespace std;

class Ponto{
    private:
        float x;
        float y;
    public:
        Ponto(float _x = 0, float _y = 0){
            x = _x;
            y = _y;
        }

        float getX(){
            return x;
        }
        float getY(){
            return y;
        }

        void setX(float _x){
            x = _x;
        }
        void setY(float _y){
            y = _y;
        }

        float distancia(Ponto p){
            return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
        }

        string toString(){
            return to_string(3);
        }
        string toString(int casasDecimais){
            float aux = pow(10, casasDecimais);
            string strX = to_string(round(x * aux) / aux);
            string strY = to_string(round(y * aux) / aux);

            return "(" + strX + ", " + strY + ")";
        }
};

int main(){
    

    return 0;
}