// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:19
// Description:
#include "../base/logging.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace base;
using namespace std;
int main(int argc, char** argv) {
  LOG::s_logging_level = 3;
  int a = 3;
  VLOG(3) << "hello world level 3 : " << a;
  VLOG(4) << "hello world level 4";
  VLOG(2) << "hello world level 2";
  VLOG(1) << "hello world level 1";
  return 0;
}
