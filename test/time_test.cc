// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:41
// Description:
#include "../base/timer.h"
#include "../base/logging.h"

using namespace base;
int main(int argc, char** argv) {
  base::LOG::s_logging_level = 3;
  VLOG(3) << GetTimeInSecond();
  VLOG(3) << GetTimeInMs();
  VLOG(3) << GetTimeInUsec();
}
