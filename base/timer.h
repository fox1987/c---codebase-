// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:50:34
// Description:
#include <time.h>
#include <sys/time.h>
#include "types.h"

namespace base {
const int64_t kTen9 = 1000000000;
const int64_t kTen6 = 1000000;
const int64_t kTen3 = 1000;

inline time_t GetTimeInSecond() {
  struct timeval now;
  gettimeofday(&now, NULL);
  return now.tv_sec;
}
inline time_t GetTimeInMs() {
  struct timeval now;
  gettimeofday(&now, NULL);
  return now.tv_sec * kTen3 + now.tv_usec / kTen3;
}

inline time_t GetTimeInUsec() {
  struct timeval now;
  gettimeofday(&now, NULL);
  return now.tv_sec * kTen6 + now.tv_usec;
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
