#include <iostream>
#include <thread>
#include "func.h"

using namespace std;
int main () {
    std::cout << "------------ Test main ------------\n";

    int a = 5, b = 2;
    double result = 0;

    dowork(a);
    std::thread extra (print_dowork, std::ref(a));
    this_thread::sleep_for(chrono::milliseconds(500));

    std::thread extra2 (print_dowork, std::ref(a));
    this_thread::sleep_for(chrono::milliseconds(500));
    //print_dowork(a);

    for (int i = 1; i < 31; ++i)
    {
        std::cout << "------------ MAIN WORK\t" << "Thread id: " << std::this_thread::get_id() << " ITERATION: #" << i << " ------------\n";
        std::cout << "a = " << a << " b = " << b << " pow(a,b) = " << pow(a,b) << "\n";
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    extra.join();
    extra2.join(); 
    return 0;
}