#ifndef PACKMAN_MAPFACTORY_HH
#define PACKMAN_MAPFACTORY_HH

#include "../../Entities/Map.hh"
#include "MonsterFactory.hh"
#include <vector>

class MapFactory {
public:
    MapFactory();

private:
    Map* createMap();
};


#endif //PACKMAN_MAPFACTORY_HH
