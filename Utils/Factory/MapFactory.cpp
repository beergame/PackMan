#include "MapFactory.hh"

MapFactory::MapFactory() {
    createMap();
}

Map *MapFactory::createMap() {
    std::vector<std::vector<int>> map(401, std::vector<int>(401));
    for (int i = 1; i < 22; i++) {
        for (int j = 1; j < 22; j++) {
            map[i][j] = 1;
        }
    }
    map[1][1] = 2;
    map[1][20] = 2;
    map[20][1] = 2;
    map[20][20] = 2;

    for (int i = 0; i < 22; i++) {
        map[0][i] = 3;
        map[21][i] = 3;
        map[i][0] = 3;
        map[i][21] = 3;
    }

    Map* result = new Map(map);
    return result;
}
