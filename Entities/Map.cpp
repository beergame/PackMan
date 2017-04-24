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

std::vector<std::vector<int> > Map::getMap() {
    return map;
}

Map::Map(std::vector<std::vector<int> > map) {
    Map::map = map;
}

void Map::cleanElement(double X, double Y) {
    int PositionX = (int)round(X);
    int PositionY = (int)round(Y);

    map[PositionX][PositionY] = 0;
}

void Map::Draw(sf::RenderWindow *window) {
    sf::Texture texture;
    for(int i = 0; i < map.size(); i++){
        for(int j = 0; j < map[i].size(); j++){
            if (map[i][j] == 1) {
                texture.loadFromFile("../Sprites/Beer.png");
            } else if (map[i][j] == 2) {
                texture.loadFromFile("../Sprites/Beers.png");
            }
            sf::Sprite sprite(texture, sf::IntRect(0,0,120,120));
            sprite.setScale(1 / 15, 1 / 15);
            sprite.setPosition(50 + (8 * i), 50 + (8 * j));
            window->draw(sprite);
        }
    }
}
