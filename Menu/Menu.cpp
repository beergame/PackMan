//
// Created by Roland Coulibaly on 03/05/2017.
//

#include "Menu.hh"

Menu::Menu(float width, float height)
{
    font.loadFromFile("../blackWolf.ttf");
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play PackMan");
    menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

    selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::Draw(sf::RenderWindow &window)
{
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
        window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

int Menu::ExecMenu()
{
    sf::VideoMode videoMode(600, 600);
    sf::RenderWindow window(videoMode, "Packman Menu");
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                return 3;
            }
            if ((event.type == sf::Event::KeyReleased) &&
                    (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::Up))
                menu.MoveUp();
            if ((event.type == sf::Event::KeyReleased) &&
                (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down))
                menu.MoveDown();
            if ((event.type == sf::Event::KeyReleased) &&
                (event.key.code == sf::Keyboard::Return))
            {
                if (menu.GetPressedItem() == 0)
                    return 1;
                if (menu.GetPressedItem() == 1)
                    return 2;
            }
        }

        window.clear();

        menu.Draw(window);

        window.display();
    }
    return 0;
}
