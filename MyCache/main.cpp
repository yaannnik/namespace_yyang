#include <MyCache.h>
#include <unistd.h>

#include <functional>
#include <thread>

std::mutex mtx;

void foo(int start, int end) {
    for (int i = start; i <= end; i++) {
        bool rc = yyang::MyCache<int, std::string>::instance().insert(i, "Val");
        if (rc) {
            std::unique_lock<std::mutex> lock(mtx);
            std::cout << __TIMESTAMP__ << "insert [" << i
                      << ", Val] into my cache" << std::endl;
        }
        sleep(1);
    }
}

int main() {
    std::thread t1(std::bind(foo, 1, 10));
    std::thread t2(std::bind(foo, 11, 20));

    t1.join();
    t2.join();
    return 0;
}