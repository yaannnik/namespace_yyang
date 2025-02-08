#include <mysingletonmeyers.h>

#include <mutex>

namespace yyang {

std::once_flag MySingletonMeyers::m_flag;

MySingletonMeyers::MySingletonMeyers()
{
    std::cout << "Construct MySingletonMeyers object" << std::endl;
}

MySingletonMeyers::~MySingletonMeyers()
{
    std::cout << "De-Contruct MySingletonMeyers object" << std::endl;
}

MySingletonMeyers &MySingletonMeyers::instance()
{
    static MySingletonMeyers instance;
    std::call_once(MySingletonMeyers::m_flag, &MySingletonMeyers::init);

    return instance;
}

void MySingletonMeyers::log(const std::string &str)
{
    std::cout << __TIMESTAMP__ << " MySingletonMeyers: " << str << std::endl;
}

void MySingletonMeyers::init() { std::cout << "Some init here" << std::endl; }

}  // namespace yyang