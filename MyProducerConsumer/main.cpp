#include <functional>
#include <iostream>
#include <semaphore>
#include <thread>

#define SWITCH_LAMBA true

namespace yyang {
std::counting_semaphore spToProducer{1};
std::counting_semaphore spToConsumer{0};

void producerWorker(std::function<void()> f)
{
    while (1) {
        spToProducer.acquire();

        std::cout << "Producer waked up\n";
        f();

        spToConsumer.release();
    }
}

void consumerWorker(std::function<void()> f)
{
    while (1) {
        spToConsumer.acquire();

        std::cout << "Consumer waked up\n";
        f();

        spToProducer.release();
    }
}

void foo(const std::string& str) { std::cout << str << " is working\n"; }

}  // namespace yyang

int main()
{
    std::string consumer{"Consumer"}, producer{"Producer"};

#if SWITCH_LAMBA
    auto fp = [producer]() { yyang::producerWorker([producer]() { yyang::foo(producer); }); };
    auto fc = [consumer]() { yyang::consumerWorker([consumer]() { yyang::foo(consumer); }); };

    std::thread tProducer(fp);
    std::thread tConsumer(fc);

    tProducer.join();
    tConsumer.join();
#else
    std::function<void()> fooP = std::bind(yyang::foo, producer);
    std::function<void()> fooC = std::bind(yyang::foo, consumer);

    std::function<void()> fp = std::bind(yyang::producerWorker, fooP);
    std::function<void()> fc = std::bind(yyang::consumerWorker, fooC);

    std::thread tProducer(fp);
    std::thread tConsumer(fc);

    tProducer.join();
    tConsumer.join();
#endif

    return 0;
}