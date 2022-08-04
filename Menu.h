//
// Created by zains on 4/18/2022.
//

#ifndef SFML_PROJECT_MENU_H
#define SFML_PROJECT_MENU_H

#include "ItemList.h"

class Menu : public GuiComponentAdapter{
public:
    Menu();
    Menu(float x, float y, int size);

    void setLabel(string label);
    void setPosition(float x, float y);
    void disableList();
    void enableList();
    bool listStatus();
    void setLabels(vector<string> strings);
    vector<Item> getList();



    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::Rect<float> getGlobalBounds();

private:
    ItemList menu;
    Item title;
    string listlabel;
    bool isEnabled;
};


#endif //SFML_PROJECT_MENU_H
