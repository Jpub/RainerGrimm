// sleepAndWait.cpp

#include <utility>
#include <iostream>
#include <future>
#include <thread>
#include <utility>

using namespace std;
using namespace std::chrono;

mutex coutMutex;

long double getDifference(const steady_clock::time_point& tp1, 
                          const steady_clock::time_point& tp2){
    const auto diff= tp2 - tp1;
    const auto res= duration <long double, milli> (diff).count();
    return res;
}

void producer(promise<int>&& prom){
    cout << "PRODUCING THE VALUE 2011\n\n"; 
    this_thread::sleep_for(seconds(5));
    prom.set_value(2011);
}

void consumer(shared_future<int> fut,
              steady_clock::duration dur){
    const auto start = steady_clock::now();
    future_status status= fut.wait_until(steady_clock::now() + dur);
    if ( status == future_status::ready ){
        lock_guard<mutex> lockCout(coutMutex);
        cout << this_thread::get_id() << " ready => Result: " << fut.get() 
             << endl;
    }
    else{
        lock_guard<mutex> lockCout(coutMutex);
        cout << this_thread::get_id() << " stopped waiting." << endl;
    }
    const auto end= steady_clock::now();
    lock_guard<mutex> lockCout(coutMutex);
    cout << this_thread::get_id() << " waiting time: " 
         << getDifference(start,end) << " ms" << endl;
}

void consumePeriodically(shared_future<int> fut){
    const auto start = steady_clock::now();
    future_status status;
    do {
        this_thread::sleep_for(milliseconds(700));
        status = fut.wait_for(seconds(0));
        if (status == future_status::timeout) {
            lock_guard<mutex> lockCout(coutMutex);
            cout << "     " << this_thread::get_id() 
                 << " still waiting." << endl;
        }
        if (status == future_status::ready) {
            lock_guard<mutex> lockCout(coutMutex);
            cout << "     " << this_thread::get_id() 
                 << " waiting done => Result: " << fut.get() << endl;
        }
    } while (status != future_status::ready); 
    const auto end= steady_clock::now();
    lock_guard<mutex> lockCout(coutMutex);
    cout << "     " << this_thread::get_id() << " waiting time: " 
         << getDifference(start,end) << " ms" << endl;
}

void consumeWithBackoff(shared_future<int> fut){
    const auto start = steady_clock::now();
    future_status status;
    auto dur= milliseconds(1);
    do {
        this_thread::sleep_for(dur);
        status = fut.wait_for(seconds(0));
        dur *= 2;
        if (status == future_status::timeout) {
            lock_guard<mutex> lockCout(coutMutex);
            cout << "         " << this_thread::get_id() 
                 << " still waiting." << endl;
        }
        if (status == future_status::ready) {
            lock_guard<mutex> lockCout(coutMutex);
            cout << "         " << this_thread::get_id() 
                 << " waiting done => Result: " << fut.get() << endl;
        }
    } while (status != future_status::ready);
    const auto end= steady_clock::now();
    lock_guard<mutex> lockCout(coutMutex);
    cout << "         " << this_thread::get_id() 
         << " waiting time: " << getDifference(start,end) << " ms" << endl;
}

int main(){
    
    cout << endl;

    promise<int> prom;
    shared_future<int> future= prom.get_future();
    thread producerThread(producer, move(prom));
    
    thread consumerThread1(consumer, future, seconds(4));
    thread consumerThread2(consumer, future, seconds(20));
    thread consumerThread3(consumePeriodically, future);
    thread consumerThread4(consumeWithBackoff, future);
    
    consumerThread1.join();
    consumerThread2.join();
    consumerThread3.join();
    consumerThread4.join();
    producerThread.join();
    
    cout << endl;

}
