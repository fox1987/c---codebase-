// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:41
// Description:
#include "../base/types.h"
#include "../base/logging.h"

using namespace base;
int main(int argc, char** argv) {
  base::LOG::s_logging_level = 3;
  int array[10];
  VLOG(3) << arraysize(array);
  std::string str[10];
  VLOG(3) << arraysize(str);
  return 0;
}
