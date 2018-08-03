// schoolDay.cpp

#include <iostream>
#include <chrono>

using namespace std::literals::chrono_literals;
using namespace std::chrono;
using namespace std;

int main(){

  cout << endl;

  constexpr auto schoolHour= 45min;

  constexpr auto shortBreak= 300s;
  constexpr auto longBreak= 0.25h;

  constexpr auto schoolWay= 15min;
  constexpr auto homework= 2h;

  constexpr auto schoolDaySec= 2*schoolWay + 6 * schoolHour + 4 * shortBreak + 
                               longBreak + homework;

  cout << "School day in seconds: " << schoolDaySec.count() << endl;

  constexpr duration<double, ratio<3600>> schoolDayHour = schoolDaySec;
  constexpr duration<double, ratio<60>> schoolDayMin = schoolDaySec;
  constexpr duration<double, ratio<1,1000>> schoolDayMilli= schoolDaySec;

  cout << "School day in hours: " << schoolDayHour.count() << endl;
  cout << "School day in minutes: " << schoolDayMin.count() << endl;
  cout << "School day in milliseconds: " << schoolDayMilli.count() << endl;

  cout << endl;

}
