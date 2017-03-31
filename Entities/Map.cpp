#include "Map.hh"

/**
 *
 * @param X
 * @param Y
 * @return Element present at [X][Y] coordinate
 * 0 => empty case
 * 1 => simple pillule
 * 2 => power-up
 * 3 => wall
 * 4 => bonus score (?)
 */
int Map::checkMap(double X, double Y) {
    int PositionX = (int)round(X);
    int PositionY = (int)round(Y);

    return map[PositionX][PositionY];
}

std::vector<std::vector<int>> Map::getMap() {
    return map;
}

Map::Map(std::vector<std::vector<int>> map) {
    Map::map = map;
}

void Map::cleanElement(double X, double Y) {
    int PositionX = (int)round(X);
    int PositionY = (int)round(Y);

    map[PositionX][PositionY] = 0;
}
