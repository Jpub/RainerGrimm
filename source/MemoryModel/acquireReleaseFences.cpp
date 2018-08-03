// acquireReleaseFences.cpp

#include <atomic>
#include <thread>
#include <iostream>
#include <string>

using namespace std;
 
atomic<string*> ptr;
int data;
atomic<int> atoData;
 
void producer(){
    string* p  = new string("C++11");
    data = 2011;
    atoData.store(2014, memory_order_relaxed);
    atomic_thread_fence(memory_order_release);
    ptr.store(p, memory_order_relaxed);
}
 
void consumer(){
    string* p2;
    while (!(p2 = ptr.load(memory_order_relaxed)));
    atomic_thread_fence(memory_order_acquire);
    cout << "*p2: " << *p2 << endl;
    cout << "data: " << data << endl;
    cout << "atoData: " << atoData.load(memory_order_relaxed) << endl;
}
 
int main(){
    
    cout << endl;
    
    thread t1(producer);
    thread t2(consumer);
    
    t1.join();
    t2.join();
    
    delete ptr;
    
    cout << endl;
    
}
