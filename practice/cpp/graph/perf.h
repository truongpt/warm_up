#include <iostream>
#include <chrono>
#include <memory>

class Performance {
public:
    std::chrono::system_clock::time_point start;
    Performance() {
        start = std::chrono::system_clock::now();
    }
    ~Performance() {
        std::chrono::duration<double> dur= std::chrono::system_clock::now() - start;
        std::cout << "time : " << dur.count() << " seconds" << std::endl;
    }
};


#define PERF (std::unique_ptr<Performance> (p)(new Performance()))
