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
	int PositionX = (int) round(X);
	int PositionY = (int) round(Y);

	return map[PositionX][PositionY];
}

std::vector<std::vector<int> > Map::getMap() {
	return map;
}

Map::Map(std::vector<std::vector<int> > map) {
	Map::map = map;
}

void Map::cleanElement(double X, double Y) {
	int PositionX = (int) round(X);
	int PositionY = (int) round(Y);

	map[PositionX][PositionY] = 0;
}

void Map::Draw(sf::RenderWindow *window) {
	sf::Texture texture;
	sf::Texture texture2;

	/* fix low fps -> don't call "loadFromFile" in loop */
	texture.loadFromFile("../Sprites/Beer.png");
	texture2.loadFromFile("../Sprites/Beers.png");
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 1) {
				sf::Sprite sprite(texture, sf::IntRect(i, j, 120, 120));
				sprite.setPosition((i * 16) + 57, (j * 16) + 57);
				sprite.setScale(0.1, 0.1);
				window->draw(sprite);
			} else if (map[i][j] == 2) {
				sf::Sprite sprite(texture2, sf::IntRect(i, j, 120, 120));
				sprite.setPosition((i * 16) + 55, (j * 16) + 55);
				sprite.setScale(0.22, 0.20);
				window->draw(sprite);
			}
		}
	}
}
