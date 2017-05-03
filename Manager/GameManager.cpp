#include "GameManager.hh"

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
	monsterManager->setPackmanObserver(playerManager->getPackman());
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

	while (window.isOpen() && getPlayerManager()->getPackman()->getLife()) {
		window.clear();

		Event event;
		this->Update();
		this->getFps(&window);
        if (isVictorious()) {
            window.close();
            Menu::VictoryMenu();
            continue;
        }
		/* draw game info */
		if (this->getPlayerManager()->getPackman()->isStatus()) {
			drawString(&window, 100, "Packman power up !!");
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

void GameManager::drawString(RenderWindow *window, int x, std::string str)
{
	Text text(str, font, 20);
	text.setPosition(x, 10);
	window->draw(text);
}

bool GameManager::isVictorious() {
    for (int i = 0; i < getMap()->getMap().size(); i++) {
        for (int j = 0; j < getMap()->getMap()[i].size(); j++) {
            if (getMap()->getMap()[i][j] == 1 || getMap()->getMap()[i][j] == 2)
                return false;
        }
    }
    return true;
}

int main(int ac, char **av)
{
	srand((unsigned) time(0));
	int resExecMenu = Menu::ExecMenu();
	if (resExecMenu == 2 || resExecMenu == 3)
		return -1;
	GameManager gameManager;
	gameManager.exec();

	return (0);
}
