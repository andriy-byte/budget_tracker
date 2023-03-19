

#include "Singleton.h"

template<class T>
std::shared_ptr<T> Singleton<T>::instance{nullptr};

template<class T>
std::mutex Singleton<T>::mutex_;

template<class T>
std::shared_ptr<T> Singleton<T>::getInstance() {
    std::lock_guard<std::mutex> lock(mutex_);
    if(!instance){
        instance.reset(new T());
    }
    return instance;
}