#include <iostream>
#include <cmath>

using namespace std;

class hoje{
    private:
        double x, y;
    public:
        hoje(double x=0, double y=0){
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
    hoje ponto(-2, 7);
    ponto.setXY(1, 1);
    cout << "A distancia do ponto (" << ponto.getX() << ", " << ponto.getY() << ") ate a origem eh aproximadamente: " << ponto.distancia() << endl;
    
    return 0;
}