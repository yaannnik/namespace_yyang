#ifndef MYSINGLETONLAZY_H
#define MYSINGLETONLAZY_H

#include <memory>
#include <mutex>
#include <string>

namespace yyang {

class MySingletonLazy {
public:
  static MySingletonLazy& instance();

  void log(const std::string &str);

private:
  MySingletonLazy();
  ~MySingletonLazy();

  MySingletonLazy(const MySingletonLazy &) = delete;
  MySingletonLazy &operator=(const MySingletonLazy &) = delete;

  static void init();
  static MySingletonLazy m_instance;
  static std::once_flag m_onceFlag;
};

} // namespace yyang

#endif // MYSINGLETONLAZY_H
