// clockProperties.cpp

#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std::chrono;
using namespace std;

template <typename T>
void printRatio(){ 
    cout << "  precision: " << T::num << "/" << T::den << " second " << endl;
    typedef typename ratio_multiply<T,kilo>::type MillSec;
    typedef typename ratio_multiply<T,mega>::type MicroSec;
    cout << fixed;
    cout << "             " << static_cast<double>(MillSec::num)/MillSec::den 
                            << " milliseconds " << endl;
    cout << "             " << static_cast<double>(MicroSec::num)/MicroSec::den 
                            << " microseconds " << endl;
}

int main(){
    
    cout << boolalpha << endl;
    
    cout << "std::chrono::system_clock: " << endl;
    cout << "  is steady: " << system_clock::is_steady << endl;
    printRatio<chrono::system_clock::period>();
    
    cout << endl;
    
    cout << "std::chrono::steady_clock: " << endl;
    cout << "  is steady: " << chrono::steady_clock::is_steady << endl;
    printRatio<chrono::steady_clock::period>();
    
    cout << endl;
    
    cout << "std::chrono::high_resolution_clock: " << endl;
    cout << "  is steady: " << chrono::high_resolution_clock::is_steady 
         << endl;
    printRatio<chrono::high_resolution_clock::period>();
    
    cout << endl;
    
}
