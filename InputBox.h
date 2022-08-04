//
// Created by zains on 4/3/2022.
//

#ifndef SFML_PROJECT_INPUTBOX_H
#define SFML_PROJECT_INPUTBOX_H
#include "ItemList.h"

class InputBox : public GuiComponentAdapter { //  just keep track of which item was clicked

public:
    InputBox();
    InputBox(float x, float y);

    void setLabel(string inputlabel);
    string getLabel();
    void setPosition(float x, float y);
    bool listShown();

    sf::Rect<float> getGlobalBounds();

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

private:
    bool showList;
    Item input;
};


#endif //SFML_PROJECT_INPUTBOX_H
