// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:50:18
// Description:
#ifndef THREAD_H_
#define THREAD_H_
#include <pthread.h>
namespace base {
class Thread {
  public:
    Thread(bool joinable = false) : started_(false), joinable_(joinable) { }
    virtual ~Thread() {}

    pthread_t tid() const {
      return tid_;
    }

    void SetJoinable(bool joinable) {
      if (!started_) {
        joinable_ = joinable;
      }
    }

    void Start();
    
    void Join();
  protected:
    virtual void Run() = 0;

    static void* ThreadRunner(void* arg) {
      Thread* t = reinterpret_cast<Thread*>(arg);
      t->Run();
      return NULL;
    }
    pthread_t tid_;
    bool started_;
    bool joinable_;

  private:

};
}
#endif
