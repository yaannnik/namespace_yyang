#ifndef MYCACHE_H
#define MYCACHE_H

#include <iostream>
#include <map>
#include <mutex>
#include <shared_mutex>

namespace yyang {

template <typename K, typename V>
class MyCache
{
   public:
    static MyCache &instance();

    bool insert(const K &key, const V &val);
    bool update(const K &key, const V &val);

    bool           erase(const K &key);
    const V *const query(const K &key) const;

   private:
    MyCache() = default;
    ~MyCache() = default;

    MyCache(const MyCache &obj) = delete;
    MyCache &operator=(const MyCache &obj) = delete;

    std::map<K, V>            m_cache;
    mutable std::shared_mutex m_mtx;
};
}  // namespace yyang

#endif