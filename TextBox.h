//
// Created by zains on 3/26/2022.
//

#ifndef SFML_PROJECT_TEXTBOX_H
#define SFML_PROJECT_TEXTBOX_H
#include "SFML/Graphics.hpp"
#include <iostream>
using namespace std;
class TextBox : public sf::RectangleShape{
public:
    TextBox();
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void setPosition(float x, float y);
    void setSize(float x, float y);

    sf::Vector2f getPosition() const;
private:
    sf::RectangleShape rect;
};


#endif //SFML_PROJECT_TEXTBOX_H
