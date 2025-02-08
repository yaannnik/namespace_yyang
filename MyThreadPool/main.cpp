#include <MyThreadPool.h>

#include <iostream>

std::mutex streamMutex;

int main()
{
    yyang::MyThreadPool mtp(3);
    mtp.start();

    for (int i = 0; i < 10; i++) {
        mtp.enqueue([i]() {
            std::unique_lock<std::mutex> lck(streamMutex);
            std::cout << "task " << i << " starts\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "task " << i << " ends\n";
        });
    }

    return 0;
}