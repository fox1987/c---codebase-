// Copyright . All Rights Reserved.
// Author: yanjl04@gmail.com
// Date: 2013-06-28 20:58:44
// Description:
#ifndef LOGGING_H_
#define LOGGING_H_
#include <sstream>
#include <stdio.h>
namespace base {
class LOG {
  public:
    LOG(const std::string& file_name,
        const std::string& func_name,
        int line_num,
        int level = 3);
    LOG(const std::string& file_name,
        int line_num,
        int level = 3);

    int CurrentProcessId();
    int CurrentThreadId();
    ~LOG();
    std::ostream& stream() {
      return m_os;
    }
  static int s_logging_level;
  private:
    std::ostringstream m_os;
    int m_level;
    std::string m_file_name;
    std::string m_func_name;
    int m_pid;
    int m_tid;
    int m_line_num;
};

#define VLOG_FUNC(level) (LOG(__FILE__, __func__, __LINE__, level).stream())
#define VLOG(level) (LOG(__FILE__, __LINE__, level).stream())
}
#endif
