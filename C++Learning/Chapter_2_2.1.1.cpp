//
//  main.cpp
//  C++Learning
//
//  Created by 华哲 on 7/25/22.
//  Copyright © 2022 华哲Inc. All rights reserved.
//

#include <iostream>
#include <thread>
#include <chrono>

class background_task {
public:
    void operator() () const {
        std::cout<< "tst!" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...df
    std::cout << "Hello, World!\n";
    background_task f;
    std::thread my_thread(f);
    std::cout << std::thread::hardware_concurrency();
    my_thread.detach();
    return 0;
}
