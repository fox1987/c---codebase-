// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:51:30
// Description:
#include "../base/thread.h"
#include "../base/logging.h"
#include <string>

namespace base {
class ThreadA : public Thread {
  public:
    ThreadA(const std::string& name): m_name(name) {
    }
  protected:
    virtual void Run() {
      while (true) {
        VLOG(3) << m_name << " Run";
        sleep(1);
      }
    }
  private:
    std::string m_name;
};
}

int main(int argc, char**argv) {
  base::ThreadA t1("t1");
  base::ThreadA t2("t2");
  t1.Start();
  t2.Start();
  sleep(60);
  return 0;
}
