// singletonCallOnce.cpp

#include <iostream>
#include <mutex>

using namespace std;

class MySingleton{

  private:
    static once_flag initInstanceFlag;
    static MySingleton* instance;
    MySingleton() = default;
    ~MySingleton() = default;

  public:
    MySingleton(const MySingleton&) = delete;
    MySingleton& operator=(const MySingleton&) = delete;

    static MySingleton* getInstance(){
      call_once(initInstanceFlag,MySingleton::initSingleton);
      return instance;
    }

    static void initSingleton(){
      instance= new MySingleton();
    }
};

MySingleton* MySingleton::instance = nullptr;
once_flag MySingleton::initInstanceFlag;

int main(){

  cout << endl;

  cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << endl;
  cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << endl;

  cout << endl;

}
