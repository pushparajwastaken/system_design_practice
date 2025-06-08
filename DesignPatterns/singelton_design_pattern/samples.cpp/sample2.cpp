#include<iostream>
using namespace std;
class Singelton{
   private:
    Singelton(){
        cout<<"Constructor Called"<<endl;
    }
    public:
    static Singelton* getInstance(){
        return new Singelton();
    }
};
int main(){
    Singelton* S1=Singelton::getInstance();
   //Constructor Called
   Singelton* S2=Singelton::getInstance();
   cout<<(S1==S2)<<endl;
   /*Constructor Called
Constructor Called
0-still not same */

}