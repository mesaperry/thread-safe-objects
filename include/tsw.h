//
// Created by mesa on 6/22/21.
//

#ifndef THREAD_SAFE_WRAPPER_TSW_H
#define THREAD_SAFE_WRAPPER_TSW_H

#include <utility>
#include <mutex>
#include <thread>

namespace tsw {

    template <typename T>
    class Mutex {
    public:
        Mutex(T&& obj) : _obj(std::move(obj)) {}

        std::mutex& getMutex() {
            return _mutex;
        }

        T& getObj() {
            return _obj;
        }

    private:
        T _obj;
        std::mutex _mutex;
    };

}
#endif //THREAD_SAFE_WRAPPER_TSW_H
