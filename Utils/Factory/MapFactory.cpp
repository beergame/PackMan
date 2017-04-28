#include "MapFactory.hh"

MapFactory::MapFactory() {
}

Map *MapFactory::createMap() {
    std::vector<std::vector<int>> map(28, std::vector<int>(31));
    for (int i = 1; i < 28; i++) {
        for (int j = 1; j < 31; j++) {
            map[i][j] = 1;
        }
    }
    map[3][1] = 2;
    map[3][26] = 2;
    map[23][1] = 2;
    map[23][26] = 2;

    for (int j = 0; j < 31; j++) {
        map[0][j] = 3;
        map[27][j] = 3;
    }

    for (int i = 0; i < 28; i++) {
        map[i][0] = 3;
        map[i][30] = 3;
    }

    map = setInternalWall(map);

    Map* result = new Map(map);
    return result;
}

std::vector<std::vector<int>> MapFactory::setInternalWall(std::vector<std::vector<int>> map) {
    for (int i = 1; i < 5; i++) {
        for (int j = 13; j < 15; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 2; i < 5; i++) {
        for (int j = 2; j < 6; j++) {
            map[j][i] = 3;
        }

        for (int j = 7; j < 11; j++) {
            map[j][i] = 3;
        }

        for (int j = 16; j < 20; j++) {
            map[j][i] = 3;
        }

        for (int j = 21; j < 26; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 6; i < 8; i++) {
        for (int j = 2; j < 6; j++) {
            map[j][i] = 3;
        }

        for (int j = 10; j < 18; j ++) {
            map[j][i] = 3;
        }

        for (int j = 22; j < 26; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 6; i < 14; i++) {
        for (int j = 7; j < 9; j++) {
            map[j][i] = 3;
        }

        for (int j = 19; j < 21; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 8; i < 11; i++) {
        for (int j = 13; j < 15; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 9; i < 11; i++) {
        for (int j = 9; j < 12; j++) {
            map[j][i] = 3;
        }

        for (int j = 16; j < 19; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 9; i < 14; i++) {
        for (int j = 1; j < 6; j++) {
            map[j][i] = 3;
        }

        for (int j = 26; j > 21; j--) {
            map[j][i] = 3;
        }
    }

    for (int i = 12; i < 17; i++) {
        for (int j = 10; j < 18; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 15; i < 20; i++) {
        for (int j = 1; j < 6; j++) {
            map[j][i] = 3;
        }

        for (int j = 7; j < 9; j++) {
            map[j][i] = 3;
        }

        for (int j = 19; j < 21; j++) {
            map[j][i] = 3;
        }

        for (int j = 26; j > 21; j--) {
            map[j][i] = 3;
        }
    }

    for (int i = 18; i < 20; i++) {
        for (int j = 10; j < 18; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 20; i < 23; i++) {
        for (int j = 13; j < 15; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 21; i < 23; i++) {
        for (int j = 2; j < 6; j++) {
            map[j][i] = 3;
        }
        for (int j = 7; j < 12; j++) {
            map[j][i] = 3;
        }
        for (int j = 16; j < 21; j++) {
            map[j][i] = 3;
        }
        for (int j = 22; j < 26; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 23; i < 26; i++) {
        for (int j = 4; j < 6; j++) {
            map[j][i] = 3;
        }

        for (int j = 22; j < 24; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 24; i < 26; i++) {
        for (int j = 1; j < 3; j++) {
            map[j][i] = 3;
        }
        for (int j = 10; j < 18; j++) {
            map[j][i] = 3;
        }
        for (int j = 25; j < 28; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 24; i < 27; i++) {
        for (int j = 7; j < 9; j++) {
            map[j][i] = 3;
        }

        for (int j = 19; j < 21; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 26; i < 29; i++) {
        for (int j = 13; j < 15; j++) {
            map[j][i] = 3;
        }
    }

    for (int i = 27; i < 29; i++) {
        for (int j = 2; j < 12; j++) {
            map[j][i] = 3;
        }
        for (int j = 16; j < 26; j++) {
            map[j][i] = 3;
        }
    }

    return map;
}
