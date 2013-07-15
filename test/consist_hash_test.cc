// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-13 15:03:58
// Description:
#include "../base/logging.h"
#include "../base/consist_hash.h"

using namespace base;
#define MaxNum 4294967296
void LookTest(ConsistHash c_hash) {
  for (int i = 1; i <= 8; ++i) {
    VLOG(3) << (MaxNum/8*i -1) << ":" << c_hash.Lookup(MaxNum/8*i -1).name;
  }
}
int main(int argc, char**argv) {
  LOG::s_logging_level = 3;
  ConsistHash c_hash;
  c_hash.AddNode("10.1.3.220");
  c_hash.AddNode("10.1.3.221");
  c_hash.AddNode("10.1.3.222");
  c_hash.AddNode("10.1.3.223");
  LookTest(c_hash);
  c_hash.AddNode("10.1.3.224");
  c_hash.AddNode("10.1.3.225");
  c_hash.AddNode("10.1.3.226");
  c_hash.AddNode("10.1.3.227");
  LookTest(c_hash);
  c_hash.DelNode("10.1.3.220");
  LookTest(c_hash);
  return 0;
}
