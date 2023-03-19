

#ifndef BUDGET_TRACKER_SINGLETON_H
#define BUDGET_TRACKER_SINGLETON_H

#include <memory>

template <class T>
class Singleton {
public:
    Singleton()=default;
    Singleton(Singleton&)=delete;

    void operator=(const Singleton&)=delete;

    static std::shared_ptr<T> getInstance();
    
private:
    static std::shared_ptr<T> instance;
    static std::mutex mutex_;


};


#endif //BUDGET_TRACKER_SINGLETON_H
