// timepointAddition.cpp

#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

using namespace std::chrono;
using namespace std;

string timePointAsString(const time_point<system_clock>& timePoint){
  time_t tp= system_clock::to_time_t(timePoint);
  return asctime(gmtime(&tp));
}

int main(){  
    
  cout << endl;
    
  time_point<system_clock> nowTimePoint= system_clock::now();
  cout << "Now:              " << timePointAsString(nowTimePoint) << endl;
     
  const auto thousandYears=  hours(24*365*1000);
  time_point<system_clock>  historyTimePoint= nowTimePoint - thousandYears;
  cout << "Now - 1000 years: " << timePointAsString(historyTimePoint) << endl;
    
  time_point<system_clock>  futureTimePoint= nowTimePoint + thousandYears;
  cout << "Now + 1000 years: " << timePointAsString(futureTimePoint) << endl;
     
}
