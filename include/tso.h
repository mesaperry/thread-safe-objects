//
// Created by mesa on 6/22/21.
//

#ifndef THREAD_SAFE_OBJECTS_TSO_H
#define THREAD_SAFE_OBJECTS_TSO_H

#include <utility>
#include <mutex>

namespace tso {

    template <class T>
    class Mutex {
    public:
        Mutex(T&& obj) : obj_(std::move(obj)) {}

    private:
        T obj_;
        std::mutex mutex_;
    };

}
#endif //THREAD_SAFE_OBJECTS_TSO_H
