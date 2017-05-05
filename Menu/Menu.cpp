#include "Menu.hh"

Menu::Menu(float width, float height)
{
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play PackMan");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	selectedItemIndex = 0;
}

Menu::~Menu() {}

void Menu::Draw(sf::RenderWindow &window, sf::Font *font)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		menu[i].setFont(*font);
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int Menu::ExecMenu()
{
	sf::VideoMode videoMode(600, 600);
	sf::RenderWindow window(videoMode, "Packman Menu");
	Menu menu(window.getSize().x, window.getSize().y);
	sf::Font font;
	font.loadFromFile("../blackWolf.ttf");

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
				return 3;
			}
			if ((event.type == sf::Event::KeyReleased) &&
				(event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up)) {
				menu.MoveUp();
			}
			if ((event.type == sf::Event::KeyReleased) &&
				(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)) {
				menu.MoveDown();
			}
			if ((event.type == sf::Event::KeyReleased) &&
				(event.key.code == sf::Keyboard::Return)) {
				if (menu.GetPressedItem() == 0) {
					return 1;
				}
				if (menu.GetPressedItem() == 1) {
					return 2;
				}
			}
		}

		window.clear();
		menu.Draw(window, &font);

		window.display();
	}
	return 0;
}

void Menu::VictoryMenu(sf::RenderWindow *victoryWindow, sf::Font *font)
{
	victoryWindow->clear();
	sf::Text text("Victory!", *font, 50);
	text.setPosition(100, 200);
	sf::Text text2("Enter to play again\nEscape to close", *font, 30);
	text2.setPosition(100, 300);

	victoryWindow->draw(text);
	victoryWindow->draw(text2);
	victoryWindow->display();
	while (victoryWindow->isOpen()) {
		sf::Event event;
		while (victoryWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				victoryWindow->close();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
				victoryWindow->close();
				GameManager gameManager;
				gameManager.exec();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
				victoryWindow->close();
			}
			victoryWindow->display();
		}
	}
}

void Menu::GameOverMenu(sf::RenderWindow *gameOverWindow, sf::Font *font)
{
	gameOverWindow->clear();
	sf::Text text("Game Over !", *font, 50);
	text.setPosition(100, 200);
	sf::Text text2("Enter to play again\nEscape to close", *font, 30);
	text2.setPosition(100, 300);

	gameOverWindow->draw(text);
	gameOverWindow->draw(text2);
	gameOverWindow->display();
	while (gameOverWindow->isOpen()) {
		sf::Event event;
		while (gameOverWindow->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				gameOverWindow->close();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Return) {
				gameOverWindow->close();
				GameManager gameManager;
				gameManager.exec();
			}
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
				gameOverWindow->close();
			}
			gameOverWindow->display();
		}
	}
}
