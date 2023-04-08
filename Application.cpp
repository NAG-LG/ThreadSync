// Example program
#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include "ThreadPool.h"
using namespace std;
std::mutex m1;
std::mutex m2;

void func(void *data) {
    std::string task_name((char*)(data));
    std::cout << task_name << std::endl;
}

int main()
{
    ThreadPool my_pool(5);
    for (int i = 1; i <= 10; i++) {
        Task t1;
        t1.call_back = (void* (*)(void*))(func);
        t1.task_name = "task number " + std::to_string(i);
        my_pool.Add_Task(t1);
    }
    my_pool.Start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    my_pool.End();
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return 0;
}
/* {    auto f1 = []() {
        std::lock_guard<std::mutex> lg1(m1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m2);
    };

    auto f2 = []() {
        std::lock_guard<std::mutex> lg1(m2);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lg2(m1);
    };

    std::thread thread1([&f1, &f2]() {
        f1();
        });

    std::thread thread2([&f1, &f2]() {
        f2();
        });

    thread1.join();
    thread2.join();

}*/