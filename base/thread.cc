// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-07-01 08:50:11
// Description:
#include "thread.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace base {

void Thread::Start() {
  pthread_attr_t attr;
  if (pthread_attr_init(&attr) != 0){
    abort();
  }
  pthread_attr_setdetachstate(
        &attr,
        joinable_ ?PTHREAD_CREATE_JOINABLE : PTHREAD_CREATE_DETACHED);

  int result = pthread_create(&tid_, &attr, &ThreadRunner, this);
  pthread_attr_destroy(&attr);

  started_ = true;
}

void Thread::Join() {
  if (!joinable_) {
    cerr << "not joinable" << endl;
    abort();
    return;
  }
  int result = pthread_join(tid_, NULL);
  if (result != 0 ) {
    cerr << "Could not join" << endl;
    abort();
    return;
  }
}
}
