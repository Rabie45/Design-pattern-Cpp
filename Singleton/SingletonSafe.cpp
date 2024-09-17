#include <iostream>
#include <thread>
#include <mutex>
#include<vector>
class SingletonSafe{
private:
    SingletonSafe() =default;
    SingletonSafe(const SingletonSafe &singleton)=delete;
    SingletonSafe(SingletonSafe &&)=delete;

    SingletonSafe& operator=(const SingletonSafe &)=delete;
    SingletonSafe& operator=(SingletonSafe &&)=delete;
    static SingletonSafe *instance;

public:
int data;
static std::mutex mtx;
  static SingletonSafe *getInstance(){
    std::lock_guard<std::mutex> lock(mtx);
    if(instance==nullptr) instance=new SingletonSafe();
    return instance;
  }
};
SingletonSafe* SingletonSafe::instance =nullptr;
std::mutex SingletonSafe::mtx;
int main(){
std::vector<std::thread> threads;
for(int i=0; i<10 ;i++){
    threads.emplace_back([i]() {
        SingletonSafe *s = SingletonSafe::getInstance();
        s->data = i;
        std::cout << "Thread " << i << " data: " << s->data << std::endl;
    });
}
for(auto& t: threads){
    if(t.joinable()){
        t.join();
    }
}
SingletonSafe *singleton = SingletonSafe::getInstance();
        std::cout << "Data " << singleton->data  << std::endl;




    return 0;
}