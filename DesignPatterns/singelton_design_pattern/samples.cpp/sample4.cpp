#include<iostream>
#include<mutex>
using namespace std;
class Singelton{
   private:
    static Singelton * instance;
    static mutex mtx;
    Singelton(){
        cout<<"Constructor Called"<<endl;
    }
    public:
    static Singelton* getInstance(){
       //lock for thread safety
       if(instance==nullptr){
        lock_guard<mutex> lock(mtx);
        if(instance==nullptr){
            
             instance=new Singelton();
        }}
        return instance;
    }
};
Singelton* Singelton::instance=nullptr;
mutex Singleton::mtx;
int main(){
    Singelton* S1=Singelton::getInstance();
   Singelton* S2=Singelton::getInstance();
   cout<<(S1==S2)<<endl;
   /*
Constructor Called
1
*/
  


}