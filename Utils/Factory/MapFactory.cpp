#include "MapFactory.hh"

MapFactory::MapFactory() {
    createMap();
}

Map *MapFactory::createMap() {
    std::vector<std::vector<int>> map(28, std::vector<int>(31));
    for (int i = 1; i < 28; i++) {
        for (int j = 1; j < 31; j++) {
            map[i][j] = 1;
        }
    }
    map[1][3] = 2;
    map[26][3] = 2;
    map[1][23] = 2;
    map[26][23] = 2;

    for (int i = 0; i < 28; i++) {
        map[i][0] = 3;
        map[i][30] = 3;
    }

    for (int j = 0; j < 31; j++) {
        map[0][j] = 3;
        map[27][j] = 3;
    }

    map = setInternalWall(map);

    Map* result = new Map(map);
    return result;
}

std::vector<std::vector<int>> MapFactory::setInternalWall(std::vector<std::vector<int>> map) {
    for (int i = 13; i < 15; i++) {
        map[1][i] = 3;
        map[2][i] = 3;
        map[3][i] = 3;
        map[4][i] = 3;
    }
    for (int i = 2; i < 6; i++) {
        map[2][i] = 3;
        map[3][i] = 3;
        map[4][i] = 3;
    }
    for (int i = 7; i < 12; i++ ) {
        map[2][i] = 3;
        map[3][i] = 3;
        map[4][i] = 3;
    }
    for (int i = 16; i < 22; i++) {
        map[2][i] = 3;
        map[3][i] = 3;
        map[4][i] = 3;
    }

    for (int i = 24; i < 18; i++) {
        map[2][i] = 3;
        map[3][i] = 3;
        map[4][i] = 3;
    }

    return map;
}
