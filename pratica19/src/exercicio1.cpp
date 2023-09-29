#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
        vector<string> getItens(){
            return itens;
        }
        void setItens(vector<string> itens){
            this->itens = itens;
        }

        bool inserirItem(string s){
            for(string item : itens){
                if(item == s)
                    return false;
            }
            itens.push_back(s);
            return true;
        }

        bool deleteItem(string s){
            int i;
            for(i = 0; i < itens.size(); i++){
                if(itens[i] == s){
                    itens.erase(itens.begin() + i);
                    return true;
                }
            }
            return false;
        }

};

int main(){


    return 0;
}