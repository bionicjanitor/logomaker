//
// Created by zains on 4/18/2022.
//

#ifndef SFML_PROJECT_MENUBAR_H
#define SFML_PROJECT_MENUBAR_H

#include "Menu.h"

class MenuBar : public GuiComponentAdapter {
public:
    MenuBar();
    MenuBar(float x, float y);

    void pushback(string label);
    void setPostition(float x, float y);
    void setLabel(int position, string label);


    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds();

private:
    vector<Menu> list;
    float x = 0;
    float y = 0;
    int number = 1;
    bool isEnabled;
};


#endif //SFML_PROJECT_MENUBAR_H
