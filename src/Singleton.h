

#ifndef BUDGET_TRACKER_SINGLETON_H
#define BUDGET_TRACKER_SINGLETON_H

#include <memory>

template<class T>
class Singleton {
public:
    Singleton(Singleton &) = delete;

    void operator=(const Singleton &) = delete;

    static T &getInstance();

protected:
    Singleton() = default;

private:
    static std::unique_ptr<T> instance;
    static std::mutex mutex_;
};


template<class T>
std::unique_ptr<T> Singleton<T>::instance{nullptr};

template<class T>
std::mutex Singleton<T>::mutex_;

template<class T>
T &Singleton<T>::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    static const std::unique_ptr<T> instance{new T{}};
    return *instance;
}


#endif //BUDGET_TRACKER_SINGLETON_H
