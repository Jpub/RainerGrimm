// timeSinceEpoch.cpp

#include <chrono>
#include <iostream>

using namespace std;

int main(){

  cout << fixed << endl;
  
  cout << "Time since 1.1.1970:\n" << endl;

  const auto timeNow= chrono::system_clock::now();
  const auto duration= timeNow.time_since_epoch();
  cout << duration.count() << " nanoseconds " << endl;

  typedef chrono::duration<long double, ratio<1, 1000000>> MyMicroSecondTick;
  MyMicroSecondTick micro(duration);
  cout << micro.count() << " microseconds" << endl;
  
  typedef chrono::duration<long double, ratio<1, 1000>> MyMilliSecondTick;
  MyMilliSecondTick milli(duration);
  cout << milli.count() << " milliseconds" << endl;
  
  typedef chrono::duration<long double> MySecondTick;
  MySecondTick sec(duration);
  cout << sec.count() << " seconds " << endl;
  
  typedef chrono::duration<double, ratio<60>> MyMinuteTick;
  MyMinuteTick myMinute(duration);
  cout << myMinute.count() << " minutes" << endl;

  typedef chrono::duration<double, ratio<60*60>> MyHourTick;
  MyHourTick myHour(duration);
  cout << myHour.count() << " hours" << endl;
  
  typedef chrono::duration<double, ratio<60*60*24*365>> MyYearTick;
  MyYearTick myYear(duration);
  cout << myYear.count() << " years" << endl;

  typedef chrono::duration<double, ratio<60*45>> MyLessonTick;
  MyLessonTick myLesson(duration);
  cout << myLesson.count() << " lessons" << endl;

  cout << endl;

}
