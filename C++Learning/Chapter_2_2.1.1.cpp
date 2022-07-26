//
//  main.cpp
//  C++Learning
//
//  Created by 华哲 on 7/25/22.
//  Copyright © 2022 华哲Inc. All rights reserved.
//

#include <iostream>
#include <thread>

class background_task {
public:
    void operator() () const {
        std::cout<< "tst!" << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    background_task f;
    std::thread my_thread(f);
    my_thread.join();
    return 0;
}
