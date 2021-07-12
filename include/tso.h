//
// Created by mesa on 6/22/21.
//

#ifndef THREAD_SAFE_OBJECT_TSO_H
#define THREAD_SAFE_OBJECT_TSO_H

#include <utility>
#include <mutex>
#include <thread>

namespace tso {

    template <typename T>
    class Mutex {
    public:
        Mutex(T&& obj) : obj_(std::move(obj)) {}

        std::mutex& getMutex() {
            return mutex_;
        }

        T& getObj() {
            return obj_;
        }

    private:
        T obj_;
        std::mutex mutex_;
    };

}
#endif //THREAD_SAFE_OBJECT_TSO_H
