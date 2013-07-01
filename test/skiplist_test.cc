// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:41
// Description:
#include "../base/skiplist.h"
#include <iostream>
#include <map>
#include <utility>
#include "../base/timer.h"
#include "../base/logging.h"
using namespace std;

const int kMax = 10000000;
int main(int argc, char** argv) {
  base::LOG::s_logging_level = 3;
  base::Timer timer;
  base::SkipList skip_list(32);
  cout << "max_level:" << skip_list.max_level() << endl;
  skip_list.Show();
  for (int i = 0; i < kMax; ++i) {
    skip_list.Insert(i);
  }
  cout << "SkipList Using time " << timer() << " ms" << endl;
  timer.Restart();
  map<int,int> int_map;
  for (int i = 0; i < kMax; ++i) {
    int_map.insert(pair<int,int>(i,i));
  }
  cout << "Map Using time " << timer() << " ms" << endl;
  /*
  skip_list.Show();
  skip_list.Find(3);
  skip_list.Find(7);
  skip_list.Find(21);
  timer.Restart();
  for (int i = 0; i < 20; ++i) {
    skip_list.Delete(i);
    // skip_list.Show();
  }
  cout << "Using time " << timer() << " ms" << endl;*/
  return 0;
}
