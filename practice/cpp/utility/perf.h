// Calculate performance

#ifndef _PERF_
#define _PERF_

#include <chrono>
#include <iostream>
#include <memory>

using namespace std;

#define TIME_SCOPE(name) std::unique_ptr<TimeCalc> test(new TimeCalc(name));

class TimeCalc {
public:
    TimeCalc(string name) {
        proc_name = name;
        start = std::chrono::steady_clock::now();
    }

    ~TimeCalc() {
        auto end = std::chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = end-start;
        cout << "elapsed time of " << proc_name << ": " << elapsed_seconds.count() << "s" << endl;
    }
    std::chrono::time_point<std::chrono::steady_clock> start;
    string proc_name;
};

#endif //_PERF_
