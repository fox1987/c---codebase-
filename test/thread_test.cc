// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:51
// Description:
#include "../base/thread.h"
#include <iostream>
using namespace std;

class WorkThread : public base::Thread {
  protected:
    virtual void Run() {
      while (true) {
        cout << "Thread Run" << endl;
        sleep(1);
      }
    }
};

int main(int argc, char** argv) {
  WorkThread t;
  t.Start();
  sleep(60);
  return 0;
}
