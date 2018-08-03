// nonsynchronized.cpp

#include <chrono>
#include <iostream>
#include <vector>
#include <thread>

using namespace std::chrono_literals;
using namespace std;

int i= 0;

void increment(){
  synchronized{ 
    cout << ++i << " ,";
    this_thread::sleep_for(1ns);
  }
}

int main(){
  
  cout << endl;
    
  vector<thread> vecSyn(10);
  vector<thread> vecUnsyn(10);
    
  for(auto& thr: vecSyn)
    thr = thread([]{ for(int n = 0; n < 10; ++n) increment(); });
  for(auto& thr: vecUnsyn)
    thr = thread([]{ for(int n = 0; n < 10; ++n) cout << ++i << " ,"; });
    
  for(auto& thr: vecSyn) thr.join();
  for(auto& thr: vecUnsyn) thr.join();
  
  cout << "\n\n";
  
}
