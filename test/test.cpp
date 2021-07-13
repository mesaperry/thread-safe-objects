//
// Created by mgperry on 7/1/21.
//

#include "tso.h"

#include <gtest/gtest.h>

#include <chrono>

TEST(MutexTest, ConcatenateStrings) {
    tso::Mutex<std::string> obj("");
    std::string str1 = "fuahwovnfjcwfiijfeowdewgrfvafklnfwevnbviowhcnqoiwdfwe";
    std::string str2 = "ialhgjonvkjdfnvjcnscqwneojniwvonhnjkbnsvjkcn";
    auto append = [&obj](std::string suffix){
        std::scoped_lock lock(obj.getMutex());
        for (auto ch : suffix) {
            obj.getObj() += ch;
            std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    };
    std::thread t1(append, str1);
    std::this_thread::sleep_for(std::chrono::microseconds(700));
    std::thread t2(append, str2);
    t1.join();
    t2.join();
    EXPECT_EQ(obj.getObj().size(), str1.size() + str2.size());
    for (int i = 0; i < obj.getObj().size(); i++) {
        EXPECT_EQ(obj.getObj()[i], (str1 + str2)[i]) << "Strings differ at index " << i;
    }
}
