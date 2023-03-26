// Example program
#include <iostream>
#include <string>
#include <mutex>
#include <thread>

using namespace std;
std::mutex m1;
std::mutex m2;



int main()
{
    auto f1 = []() {
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

}