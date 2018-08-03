// now.cpp

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std::chrono;

template <typename T>
void durationSinceEpoch(const T dur){
    std::cout << "     Counts since epoch:  " << dur.count() << std::endl;
    typedef duration<double, std::ratio<60>> MyMinuteTick;
    const MyMinuteTick myMinute(dur);
    std::cout << std::fixed;
    std::cout << "     Minutes since epoch: "<< myMinute.count() << std::endl;
    typedef duration<double, std::ratio<60*60*24*365>> MyYearTick;
    const MyYearTick myYear(dur);
    std::cout << "     Years since epoch:   " << myYear.count() << std::endl;
}
    
int main(){
    
    std::cout << std::endl;
    
    system_clock::time_point timeNowSysClock = system_clock::now(); 
    system_clock::duration timeDurSysClock= timeNowSysClock.time_since_epoch();
    std::cout << "system_clock: " << std::endl;
    durationSinceEpoch(timeDurSysClock);
    
    std::cout << std::endl;
     
    const auto timeNowStClock = steady_clock::now(); 
    const auto timeDurStClock= timeNowStClock.time_since_epoch();
    std::cout << "steady_clock: " << std::endl;
    durationSinceEpoch(timeDurStClock);
    
    std::cout << std::endl;
    
    const auto timeNowHiRes = high_resolution_clock::now(); 
    const auto timeDurHiResClock= timeNowHiRes.time_since_epoch();
    std::cout << "high_resolution_clock: " << std::endl;
    durationSinceEpoch(timeDurHiResClock);
    
    std::cout << std::endl;

}
