#ifndef PACKMAN_MAP_HH
#define PACKMAN_MAP_HH

#include <vector>
#include <math.h>
#include "Monster.hh"

class Map {
private:
    std::vector<std::vector<int>> map;

public:
    int checkMap(double, double);
    Map(std::vector<std::vector<int>>);
    std::vector<std::vector<int>> getMap();
    void cleanElement(double, double);
};


#endif //PACKMAN_MAP_HH
