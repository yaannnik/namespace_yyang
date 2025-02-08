#include <MyCache.h>

namespace yyang {

template <typename K, typename V>
MyCache<K, V> &MyCache<K, V>::instance()
{
    static MyCache<K, V> instance;
    return instance;
}

template <typename K, typename V>
bool MyCache<K, V>::insert(const K &key, const V &val)
{
    std::unique_lock<std::shared_mutex> lock(m_mtx);
    auto [iter, ret] = m_cache.emplace(key, val);
    return ret;
}

template <typename K, typename V>
bool MyCache<K, V>::update(const K &key, const V &val)
{
    std::unique_lock<std::shared_mutex> lock(m_mtx);
    if (!m_cache.count(key)) {
        return false;
    }

    m_cache[key] = val;
    return true;
}

template <typename K, typename V>
bool MyCache<K, V>::erase(const K &key)
{
    std::unique_lock<std::shared_mutex> lock(m_mtx);
    if (!m_cache.count(key)) {
        return false;
    }

    m_cache.erase(key);
    return true;
}

template <typename K, typename V>
const V *const MyCache<K, V>::query(const K &key) const
{
    std::shared_lock<std::shared_mutex> lock(m_mtx);
    if (!m_cache.count(key)) {
        return nullptr;
    }
    // const member can only use std::map::at
    return &m_cache.at(key);
}

// don't forget declare here
template class MyCache<int, std::string>;

}  // namespace yyang