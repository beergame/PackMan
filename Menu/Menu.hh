#ifndef PACKMAN_MENU_HH
#define PACKMAN_MENU_HH

#include "SFML/Graphics.hpp"
#include "../Manager/GameManager.hh"

#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];

public:
    Menu(float width, float height);
    ~Menu();
    void Draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int static ExecMenu();
    void static VictoryMenu();
    void static GameOverMenu();
    int GetPressedItem() { return selectedItemIndex; }

};

#endif //PACKMAN_MENU_HH