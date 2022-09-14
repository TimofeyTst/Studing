#include <thread>
#include <chrono>
#include "func.h"


int pow (int n, int k)
{
    if (k > 0) 
    {
        if (k == 1) return n;
        else return n * pow (n, k-1);
    } else return -1;
}

void dowork(int &a)
{
    a += 5;
};

void print (int n, int k) 
{
    std::cout << "\t\t\t============== void print()\t" << "Thread id: " << std::this_thread::get_id() << " ==============\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "\t\t\t============== Pow started ==============\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "\t\t\t============== " << n << "^" << k << " = " << pow(n,k) <<" ==============\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout <<"\t\t\t============== End of void print() ==============\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void print_dowork(int &a)
{
    std::cout << "\t\t\t============== print_dowork() a = " << a << "\tThread id: " << std::this_thread::get_id() << " ==============\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    a += 5;
    std::cout << "\t\t\t============== new a = " << a << "\t" << "Thread id : " << std::this_thread::get_id() << " ==============\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "\t\t\t============== End of void print_dowork(int& a)\t" << "Thread id: " << std::this_thread::get_id() << " ==============\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void print_ref(double &result, int n, int k) 
{
    std::cout << "\t\t\t======= void print()\t" << "Thread id: " << std::this_thread::get_id() << " =======\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout << "\t\t\t======= Pow started\tThread id: " << std::this_thread::get_id() << " =======\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    result = pow(n,k);

    std::cout << "\t\t\t======= " << n << "^" << k << " = " << result << "\tThread id: " << std::this_thread::get_id() << " =======\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));

    std::cout <<"\t\t\t======= End of void print()\tThread id: " << std::this_thread::get_id() << " =======\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

}