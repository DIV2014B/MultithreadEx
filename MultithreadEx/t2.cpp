#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <sstream>

const double e = 2.7182818284590452353602874713527;

double sinh_impl(double x) {
    return (1 - pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double cosh_impl(double x) {
    return (1 + pow(e, (-2 * x))) / (2 * pow(e, -x));
}

double tanh_impl(double x) {
    return sinh_impl(x) / cosh_impl(x);
}

void thread_function2()
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    long d = 0;
    for (double i = 0; i < 1000000; ++i)
    {
        if (tanh_impl(i)) {
            d++;
        }
    }
    //std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    //std::chrono::milliseconds sec = std::chrono::system_clock::now() - start;
    std::stringstream ss;
    std::chrono::milliseconds mill = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    ss << "thread function:" << d << " " << mill.count() << std::endl;
    std::cout << ss.str();
}

int main2()
{
    // vector container stores threads
    for (int i = 0; i < 100; i ++) {
        std::vector<std::thread> workers;
        for (int i = 0; i < 4; i++) {
            workers.push_back(std::thread(&thread_function2));
        }
        std::cout << "main thread\n";

        // Looping every thread via for_each
        // The 3rd argument assigns a task
        // It tells the compiler we're using lambda ([])
        // The lambda function takes its argument as a reference to a thread, t
        // Then, joins one by one, and this works like barrier
        std::for_each(workers.begin(), workers.end(), [](std::thread& t)
            {
                t.join();
            });
    }
    return 0;
}