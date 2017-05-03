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

int Map::checkWays(double X, double Y)
{
	int PositionX = (int) round(X);
	int PositionY = (int) round(Y);
	int ways = 0;

	if (PositionX > 1 && PositionX < map.size() &&
			PositionY > 1 && PositionY < map[0].size()) {
		if (map[PositionX - 1][PositionY] != 3) {
			ways++;
		}
		if (map[PositionX + 1][PositionY] != 3) {
			ways++;
		}
		if (map[PositionX][PositionY - 1] != 3) {
			ways++;
		}
		if (map[PositionX][PositionY + 1] != 3) {
			ways++;
		}
	}

	return (ways > 2);
}

std::vector<std::vector<int>> Map::getMap()
{
	return map;
}

Map::Map(std::vector<std::vector<int>> map)
{
	Map::map = map;
}

void Map::cleanElement(double X, double Y)
{
	int PositionX = (int) round(X);
	int PositionY = (int) round(Y);

	map[PositionX][PositionY] = 0;
}

void Map::movePackmanFp(int dir, int oldX, int oldY, int X, int Y)
{
	if ((oldX != X) || (oldY != Y)) {
		packmanPrint[0][0] = X;
		packmanPrint[0][1] = Y;
		switch (dir) {
			case 1:
				packmanPrint[1][0] = X;
				packmanPrint[1][1] = Y - 2;
				packmanPrint[2][0] = X;
				packmanPrint[2][1] = Y + 3;
				break;
			case 2:
				packmanPrint[1][0] = X + 2;
				packmanPrint[1][1] = Y;
				packmanPrint[2][0] = X - 3;
				packmanPrint[2][1] = Y;
				break;
			case 3:
				packmanPrint[1][0] = X;
				packmanPrint[1][1] = Y + 2;
				packmanPrint[2][0] = X;
				packmanPrint[2][1] = Y - 3;
				break;
			case 4:
				packmanPrint[1][0] = X - 2;
				packmanPrint[1][1] = Y;
				packmanPrint[2][0] = X + 3;
				packmanPrint[2][1] = Y;
				break;
			default:
				break;
		}
	}
}

void Map::Draw(sf::RenderWindow *window)
{
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
