#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

class TimeManager {
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point updated;
    std::chrono::steady_clock::time_point last_updated;
    TimeManager();
    ~TimeManager();
    TimeManager(const TimeManager&) = delete;
    TimeManager& operator=(const TimeManager&) = delete;
public:
    static TimeManager& GetInstance();
    void Start();
    void Update();
    unsigned int GetElapsedTime() const;
    unsigned int GetStartedTime() const;

};


#endif //TIMEMANAGER_H
