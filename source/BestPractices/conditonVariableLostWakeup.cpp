// conditionVariableLostWakeup.cpp

#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

void waitingForWork(){
    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck);                          
    // do the work
}

void setDataReady(){
    condVar.notify_one();                        
}

int main(){

  std::thread t1(setDataReady);
  std::thread t2(waitingForWork);               

  t1.join();
  t2.join();
  
}
