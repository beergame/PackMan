#include "GameManager.hh"
//#include "../build/config.h"

using namespace sf;

GameManager::GameManager()
{
	MapFactory *mapFactory = new MapFactory();
	MonsterFactory *monsterFactory = new MonsterFactory();
	map = mapFactory->createMap();
	playerManager = new PlayerManager();
	monsterManager = new MonsterManager();
	monsterFactory->CreateMonster(monsterManager);
	playerManager->getPackman()->AddObserver(monsterManager);
	monsterManager->AddObserver(playerManager->getPackman());
	font.loadFromFile("../blackWolf.ttf");
}

PlayerManager *GameManager::getPlayerManager()
{
	return (playerManager);
}

MonsterManager *GameManager::getMonsterManager()
{
	return (monsterManager);
}

Map *GameManager::getMap()
{
	return (map);
}

void GameManager::Draw(RenderWindow *window)
{
	sf::Texture texture;
	texture.loadFromFile("../Sprites/Map.png");
	sf::Sprite sprite(texture, sf::IntRect(0, 0, 226, 246));
	sprite.setScale(2.05, 2.05);
	sprite.setPosition(49, 49);
	window->draw(sprite);
	this->getMap()->Draw(window);
	this->getPlayerManager()->getPackman()->Draw(window);
	this->getMonsterManager()->Draw(window);
}

void GameManager::Update()
{
	TimeManager::GetInstance().Update();
	this->getPlayerManager()->getPackman()->Update(this->getMap());
	this->getMonsterManager()->Update(this->getMap());
	this->getMonsterManager()
			->isPackmanVersusMonster(getPlayerManager()->getPackman());
}

void GameManager::exec()
{
	VideoMode videoMode(600, 600);
	RenderWindow window(videoMode, "Packman");
	TimeManager::GetInstance().Start();
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		window.clear();

		Event event;
		this->Update();
		this->getFps(&window);
		/* draw game info */
		if (this->getPlayerManager()->getPackman()->isStatus()) {
			drawString(&window, "Packman power up !!");
		}

		while (window.pollEvent(event)) {
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape))) {
				window.close();
			}
			if (event.type == Event::KeyPressed &&
				(event.key.code == Keyboard::Z || event.key.code == Keyboard::Up)) {
				this->getPlayerManager()->getPackman()->setDirection(1);
			} else if (event.type == Event::KeyPressed &&
					   (event.key.code == Keyboard::D || event.key.code == Keyboard::Right)) {
				this->getPlayerManager()->getPackman()->setDirection(2);
			} else if (event.type == Event::KeyPressed &&
					   (event.key.code == Keyboard::S || event.key.code == Keyboard::Down)) {
				this->getPlayerManager()->getPackman()->setDirection(3);
			} else if (event.type == Event::KeyPressed &&
					   (event.key.code == Keyboard::Q || event.key.code == Keyboard::Left)) {
				this->getPlayerManager()->getPackman()->setDirection(4);
			}
		}
		this->Draw(&window);
		window.display();
	}
}

void GameManager::getFps(RenderWindow *window)
{
	int fps = (TimeManager::GetInstance().GetElapsedTime()) ?
	1000 / TimeManager::GetInstance().GetElapsedTime() : 0;
	std::string fpsToString = std::to_string(fps) + " fps";
	Text text(fpsToString, font, 20);
	text.setPosition(0, 0);
	window->draw(text);
}

void GameManager::drawString(RenderWindow *window, std::string str)
{
	Text text(str, font, 20);
	text.setPosition(100, 10);
	window->draw(text);
}

int main(int ac, char **av)
{
	GameManager gameManager;
	gameManager.exec();

	return (0);
}
