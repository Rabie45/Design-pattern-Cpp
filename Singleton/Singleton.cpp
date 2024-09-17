#include <iostream>

class Singleton{

private:
    Singleton() =default;
    Singleton(const Singleton &singleton)=delete;
    Singleton(Singleton &&)=delete;

    Singleton& operator=(const Singleton &)=delete;
    Singleton& operator=(Singleton &&)=delete;
    static Singleton *instance;

public:
int data;
  static Singleton *getInstance(){
    if(instance==nullptr) instance=new Singleton();
    return instance;
  }
};
Singleton* Singleton::instance =nullptr;
int main(){

Singleton *singleton= Singleton::getInstance();
singleton->data=10;
std::cout<< singleton->data<<std::endl;

Singleton *singleton2= Singleton::getInstance();
singleton2->data=60;
std::cout<< singleton->data<<std::endl;

Singleton *singleton3= Singleton::getInstance();
singleton3->data=70;
std::cout<< singleton->data<<std::endl;

return 0;

}