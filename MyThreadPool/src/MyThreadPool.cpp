#include <MyThreadPool.h>

namespace yyang {
MyThreadPool::MyThreadPool(int size) : m_poolSize(size), m_clearAll(false) {}

MyThreadPool::~MyThreadPool() {
    {
        std::unique_lock<std::mutex> lck(m_mtx);
        m_clearAll = true;
    }
    m_cv.notify_one();

    for (auto &t : m_threadPool) {
        t.join();
    }
}

void MyThreadPool::start() {
    for (int i = 0; i < m_poolSize; i++) {
        // capture this to access member variables
        m_threadPool.emplace_back([this]() {
            while (1) {
                std::unique_lock<std::mutex> lck(m_mtx);
                // why need clearAll here? - To ensure it could
                // go on to return when we wwant to finish
                m_cv.wait(lck, [this]() {
                    return !m_jobQueue.empty() || m_clearAll;
                });

                // why we need clearAll here? - To avoid it
                // returns when queue is temporarily emoty
                if (m_jobQueue.empty() && m_clearAll) {
                    return;
                }

                Job job = m_jobQueue.front();
                m_jobQueue.pop();
                lck.unlock();
                job();
            }
        });
    }
}

void MyThreadPool::enqueue(const Job &job) {
    {
        std::unique_lock<std::mutex> lck(m_mtx);
        m_jobQueue.emplace(job);
    }
    m_cv.notify_one();
}

}  // namespace yyang