//
// Created by mgperry on 7/1/21.
//

#include "tsw.h"

#include <gtest/gtest.h>

#include <thread>
#include <chrono>
#include <string>

TEST(TestMutex, ConcatenateStrings) {
    TSW::Mutex<std::string> obj_wrapped("");
    std::string str1 = "fuahwovnfjcwfiijfeowdewgrfvafklnfwevnbviowhcnqoiwdfwe";
    std::string str2 = "ialhgjonvkjdfnvjcnscqwneojniwvonhnjkbnsvjkcn";
    auto append = [&obj_wrapped](std::string suffix){
        TSW::Locked<std::string> obj(obj_wrapped.lock());
        for (auto ch : suffix) {
            *obj += ch;
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    };
    std::thread t1(append, str1);
    std::this_thread::sleep_for(std::chrono::microseconds(700));
    std::thread t2(append, str2);
    t1.join();
    t2.join();
    TSW::Locked<std::string> obj(obj_wrapped.lock());
    EXPECT_EQ(obj->size(), str1.size() + str2.size());
    for (int i = 0; i < obj->size(); i++) {
        EXPECT_EQ((*obj)[i], (str1 + str2)[i]) << "Strings differ at index " << i;
    }
}
