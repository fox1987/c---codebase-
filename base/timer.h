// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:50:34
// Description:
#include <time.h>
#include <sys/time.h>

namespace base {
time_t GetTimeInMs() {
  struct timeval now;
  gettimeofday(&now, NULL);
  return now.tv_sec * 1000 + now.tv_usec / 1000;
}
class Timer {
  public:
    Timer() {
      Restart();
    }

    void Restart() {
      start_time_ = ::base::GetTimeInMs();
    }
    
    time_t Elapsed()  {
      return ::base::GetTimeInMs() -  start_time_;
    }

    time_t operator()() {
      return Elapsed();
    }
  private:
    time_t start_time_;
};
}
