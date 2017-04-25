#include "MapFactory.hh"

MapFactory::MapFactory() {
}

Map *MapFactory::createMap() {
    std::vector<std::vector<int>> map(31, std::vector<int>(28));
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j < 28; j++) {
            map[i][j] = 1;
        }
    }
    map[1][3] = 2;
    map[26][3] = 2;
    map[1][23] = 2;
    map[26][23] = 2;

    for (int i = 0; i < 31; i++) {
        map[i][0] = 3;
        map[i][27] = 3;
    }

    for (int j = 0; j < 28; j++) {
        map[0][j] = 3;
        map[30][j] = 3;
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

    for (int i = 2; i < 8; i++) {
        for (int j = 2; j < 6; j++) {
            map[i][j] = 3;
        }
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

    for (int i = 2; i < 8; i++) {
        for (int j = 24; j < 18; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 6; i < 14; i++) {
        map[i][7] = 3;
        map[i][8] = 3;
        map[i][19] = 3;
        map[i][20] = 3;
    }

    for (int i = 10; i < 18; i++) {
        map[6][i] = 3;
        map[7][i] = 3;
    }

    for (int i = 9; i < 11; i++) {
        map[9][i] = 3;
        map[10][i] = 3;
        map[11][i] = 3;
        map[16][i] = 3;
        map[17][i] = 3;
        map[18][i] = 3;
    }

    for (int i = 7; i < 11; i++) {
        map[i][13] = 3;
        map[i][14] = 3;
    }

    for (int i = 9; i < 19; i++) {
        for (int j = 1; j < 6; j++) {
            map[i][j] = 3;
        }
        for (int j = 21; j < 26; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 13; i < 18; i++) {
        for (int j = 10; j < 18; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 15; i < 20; i++) {
        for (int j = 7; j < 9; j++) {
            map[i][j] = 3;
        }
        for (int j = 19;j < 21; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 18; i < 20; i++) {
        for (int j = 10; j < 18; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 20; i < 23; i++) {
        for (int j = 13; j < 15; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 21; i < 23; i++) {
        for (int j = 2; j < 6; j++) {
            map[i][j] = 3;
        }
        for (int j = 7; j < 12; j++) {
            map[i][j] = 3;
        }
        for (int j = 16; j < 21; j++) {
            map[i][j] = 3;
        }
        for (int j = 22; j < 26; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 23; i < 26; i++) {
        for (int j = 4; j < 6; j++) {
            map[i][j] = 3;
        }

        for (int j = 22; j < 24; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 24; i < 26; i++) {
        for (int j = 1; j < 3; j++) {
            map[i][j] = 3;
        }
        for (int j = 10; j < 18; j++) {
            map[i][j] = 3;
        }
        for (int j = 26; j < 28; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 24; i < 27; i++) {
        for (int j = 7; j < 9; j++) {
            map[i][j] = 3;
        }

        for (int j = 18; j < 21; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 26; i < 29; i++) {
        for (int j = 13; j < 15; j++) {
            map[i][j] = 3;
        }
    }

    for (int i = 27; i < 29; i++) {
        for (int j = 2; j < 12; j++) {
            map[i][j] = 3;
        }
        for (int j = 16; j < 26; j++) {
            map[i][j] = 3;
        }
    }

    return map;
}
