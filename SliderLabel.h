//
// Created by zains on 5/1/2022.
//

#ifndef LOGOMAKER_SLIDERLABEL_H
#define LOGOMAKER_SLIDERLABEL_H

#include "GuiComponentAdapter.h"
#include "Fonts.h"
#include <iostream>

using namespace std;
class SliderLabel : public GuiComponentAdapter {
public:
    SliderLabel();

    void setString(string str);
    void setPosition(float x, float y);
    string getString();
    sf::Vector2f getPos() const ;

    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    sf::FloatRect getGlobalBounds() const;
private:
    sf::Text label;
};


#endif //LOGOMAKER_SLIDERLABEL_H
