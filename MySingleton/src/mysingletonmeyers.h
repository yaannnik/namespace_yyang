#ifndef MYSINGLETONMEYERS_H
#define MYSINGLETONMEYERS_H

#include <iostream>
#include <mutex>
#include <string>

namespace yyang {

class MySingletonMeyers
{
   public:
    static MySingletonMeyers &instance();

    void log(const std::string &str);

   private:
    MySingletonMeyers();
    ~MySingletonMeyers();

    MySingletonMeyers(const MySingletonMeyers &obj);
    MySingletonMeyers &operator=(const MySingletonMeyers &obj);

    static void init();

    static std::once_flag m_flag;
};

}  // namespace yyang

#endif