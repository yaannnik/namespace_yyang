#pragma once

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

namespace yyang {
typedef std::function<void()> Job;

class MyThreadPool {
 public:
  MyThreadPool(int size);

  ~MyThreadPool();

  void start();

  void enqueue(const Job& job);

 private:
  std::vector<std::thread> m_threadPool;
  std::queue<Job> m_jobQueue;

  std::mutex m_mtx;
  std::condition_variable m_cv;

  bool m_clearAll;
  int m_poolSize;
};
}  // namespace yyang