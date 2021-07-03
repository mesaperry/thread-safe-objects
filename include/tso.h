//
// Created by mesa on 6/22/21.
//

#ifndef THREAD_SAFE_OBJECTS_TSO_H
#define THREAD_SAFE_OBJECTS_TSO_H

namespace tso {

template template <class T>
class TSO {
public:
    TSO(T& object) {

    }
private:
    T _obj;
};

}

#endif //THREAD_SAFE_OBJECTS_TSO_H
