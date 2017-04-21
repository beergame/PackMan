#ifndef PACKMAN_MAPFACTORY_HH
#define PACKMAN_MAPFACTORY_HH

#include "../../Entities/Map.hh"
#include <vector>

class MapFactory {
public:
    MapFactory();
    Map* createMap();

private:
    std::vector<std::vector<int>> setInternalWall(std::vector<std::vector<int>>);
};


#endif //PACKMAN_MAPFACTORY_HH
