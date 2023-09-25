#include <iostream>

using namespace std;

long int fatorial(int n);

int main(){
    int fat[] = {5, 3, 1};

    for(int i = 0; i < 3; i++)
        cout << "Fatorial de " << fat[i] << " = " << fatorial(fat[i]) << endl;
    
    return 0;
}

long int fatorial(int n){
    long int fat = 1;
    int i;

    if(n == 0 || n == 1)
        return 1;
    
    for(i = n; i > 1; i--)
        fat = fat * i;
    
    return fat;
}
