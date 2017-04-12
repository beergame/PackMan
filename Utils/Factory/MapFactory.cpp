#include "MapFactory.hh"

MapFactory::MapFactory() {
    createMap();
}

Map *MapFactory::createMap() {
    std::vector<std::vector<int>> map(401, std::vector<int>(401));
    for (int i = 1; i < 400; i++) {
        for (int j = 1; j < 400; j++) {
            map[i][j] = 1;
        }
    }
    map[1][1] = 2;
    map[1][399] = 2;
    map[399][1] = 2;
    map[399][399] = 2;

    for (int i = 0; i < 401; i++) {
        map[0][i] = 3;
        map[400][i] = 3;
        map[i][0] = 3;
        map[i][400] = 3;
    }

    Map* result = new Map(map);
    return result;
}
