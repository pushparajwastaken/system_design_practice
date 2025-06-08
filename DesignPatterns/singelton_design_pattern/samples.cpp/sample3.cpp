/*we have been getting two different objects in all the last samples but our motto is to get a single object
so to achieve this goal we'll create a variable which will hold the instance of the singelton class it will see if it has the 
instance of the class if it has it will return the same instance and if it doesn't it will create an instance and then return it */
#include<iostream>
using namespace std;
class Singelton{
   private:
     
    static Singelton * instance;
    Singelton(){
        cout<<"Constructor Called"<<endl;
    }
    public:
    static Singelton* getInstance(){
        if(instance==nullptr){
             instance=new Singelton();
        }
        return instance;
    }
};
Singelton* Singelton::instance=nullptr;
int main(){
    Singelton* S1=Singelton::getInstance();
   Singelton* S2=Singelton::getInstance();
   cout<<(S1==S2)<<endl;
   /*
Constructor Called
1
*/
  


}