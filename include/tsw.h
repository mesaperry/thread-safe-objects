//
// Created by mgperry on 6/22/21.
//

#ifndef THREAD_SAFE_WRAPPER_TSW_H
#define THREAD_SAFE_WRAPPER_TSW_H

#include <utility>
#include <mutex>

namespace TSW {

    template <typename T>
    class Locked {
    public:
        Locked(std::pair<T*, std::mutex*> args) : obj_(*args.first), guard_(*args.second) {}

        Locked& operator= (const Locked&) = delete;

        T* operator->() {
            return &obj_;
        }

        T& operator*() {
            return obj_;
        }

    private:
        T& obj_;
        std::lock_guard<std::mutex> guard_;
    };

    template <typename T>
    class Mutex {
    public:
        Mutex(T&& obj) : obj_(std::forward<T>(obj)) {}

        T* operator->() {
            return &obj_;
        }

        std::pair<T*, std::mutex*> lock() {
            return {&obj_, &mutex_};
        }

    private:
        T obj_;
        std::mutex mutex_;
    };

}
#endif //THREAD_SAFE_WRAPPER_TSW_H
