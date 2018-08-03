// asyncVersusThread.cpp

#include <future>
#include <thread>
#include <iostream>

int main(){

  std::cout << std::endl;

  int res;
  std::thread t([&]{ res = 2000 + 11; });
  t.join();
  std::cout << "res: " << res << std::endl;             

  auto fut= std::async([]{ return 2000 + 11; });
  std::cout << "fut.get(): " << fut.get() << std::endl;   

  std::cout << std::endl;   

}
