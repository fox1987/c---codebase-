// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-06-28 20:58:33
// Description:
#include "logging.h"
#include <iomanip>
#include <sys/syscall.h>
#include <unistd.h>
#include <pthread.h>
namespace base {
int LOG::s_logging_level = 3;
LOG::LOG(const std::string& file_name,
      const std::string& func_name,
      int line_num,
      int level) 
  :m_file_name(file_name), m_func_name(func_name),
  m_line_num(line_num), m_level(level) {
    if (m_level <= s_logging_level) {
      struct tm* tm_ptr;
      time_t now = time(NULL);
      tm_ptr = localtime(&now);
      m_os << "[" << CurrentProcessId() << "/"
        << CurrentThreadId() << "/";
      m_os << tm_ptr->tm_year + 1900 << "-";
      m_os << std::setfill('0')
        << std::setw(2) << tm_ptr->tm_mon + 1 << "-"
        << std::setw(2) << tm_ptr->tm_mday << " "
        << std::setw(2) << tm_ptr->tm_hour << ":"
        << std::setw(2) << tm_ptr->tm_min << ":"
        << std::setw(2) << tm_ptr->tm_sec << "/";
      m_os << m_file_name << "(" << m_func_name << ")"
        << "(" << m_line_num << ")]:";
    }
}

LOG::LOG(const std::string& file_name,
      int line_num,
      int level) 
:m_file_name(file_name),
  m_line_num(line_num), m_level(level) {
    if (m_level <= s_logging_level) {
      struct tm* tm_ptr;
      time_t now = time(NULL);
      tm_ptr = localtime(&now);
      m_os << "[" << CurrentProcessId() << "/"
        << CurrentThreadId() << "/";
      m_os << tm_ptr->tm_year + 1900 << "-";
      m_os << std::setfill('0')
        << std::setw(2) << tm_ptr->tm_mon + 1 << "-"
        << std::setw(2) << tm_ptr->tm_mday << " "
        << std::setw(2) << tm_ptr->tm_hour << ":"
        << std::setw(2) << tm_ptr->tm_min << ":"
        << std::setw(2) << tm_ptr->tm_sec << "/";
      m_os << m_file_name << "(" << m_line_num << ")]:";
    }
}

int LOG::CurrentProcessId() {
  return getpid();
}
int LOG::CurrentThreadId() {
  return syscall(__NR_gettid);
}

LOG::~LOG() {
  if (m_level <= LOG::s_logging_level) {
    m_os << std::endl;
    fprintf(stderr,"%s", m_os.str().c_str());
    fflush(stderr);
  }
}
}
