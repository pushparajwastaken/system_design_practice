#include<iostream>
using namespace std;
class Singelton{
    public:
    Singelton(){
        cout<<"Constructor Called"<<endl;
    }
};
int main(){
    Singelton* S1=new Singelton();
    Singelton* S2=new Singelton();
    cout<<(S1==S2)<<endl;
    /*
Constructor Called
Constructor Called
0-this means both the object aren't the same
    */
}