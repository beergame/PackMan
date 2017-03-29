#include "TimeManager.hh"

TimeManager& TimeManager::GetInstance() {
    static TimeManager instance;
    return instance;
};

TimeManager::TimeManager() {};
TimeManager::~TimeManager() {};

void TimeManager::Start(){
    start = last_updated = updated = std::chrono::steady_clock::now();
};

void TimeManager::Update(){
    last_updated = updated;
    updated = std::chrono::steady_clock::now();
};

unsigned int TimeManager::GetElapsedTime() const{
    std::chrono::duration<double, std::milli> diff = updated - last_updated;
    return (unsigned int)diff.count();
};

unsigned int TimeManager::GetStartedTime() const{
    std::chrono::duration<double, std::milli> diff = updated - start;
    return (unsigned int)diff.count();
};