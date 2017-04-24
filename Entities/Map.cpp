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
    std::vector< std::vector<int> >::iterator row;
    std::vector<int>::iterator col;

    sf::Texture texture;
    for(row = map.begin(); row != map.end(); ++row){
        for(col = row->begin(); col != row->end(); ++col){
            if (*col == 1) {
                texture.loadFromFile("../Sprites/Beer.png");
            }
            if (*col == 2) {
                texture.loadFromFile("../Sprites/Beers.png");
            }
            sf::Sprite sprite(texture, sf::IntRect(0,0,120,120));
            sprite.setScale(1 / 15, 1 / 15);
            sprite.setPosition(50 + (std::distance(map.begin(), row) * 8), 50 + (*col * 8));
            window->draw(sprite);
        }
    }
}
