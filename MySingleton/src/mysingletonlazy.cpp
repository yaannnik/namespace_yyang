#include "mysingletonlazy.h"

#include <iostream>
#include <memory>
#include <mutex>

namespace yyang {

MySingletonLazy MySingletonLazy::m_instance;
std::once_flag MySingletonLazy::m_onceFlag;

MySingletonLazy::MySingletonLazy() {
  std::cout << "Construct MySingletonLazy object" << std::endl;
}

MySingletonLazy::~MySingletonLazy() {
  std::cout << "De-Construct MySingletonLazy object" << std::endl;
}

MySingletonLazy &MySingletonLazy::instance() {
  std::call_once(MySingletonLazy::m_onceFlag, &MySingletonLazy::init);
  return m_instance;
}

void MySingletonLazy::init() {}

void MySingletonLazy::log(const std::string &str) {
  std::cout << __TIMESTAMP__ << " MySingletonLazy: " << str << std::endl;
}

}  // namespace yyang
