//
// Created by zains on 2/21/2022.
//

#ifndef TYPING_TYPING_H
#define TYPING_TYPING_H


#include <SFML/Graphics.hpp>
#include "MultiText.h"


class Typing : public sf::Drawable {
public:
Typing();
void addEventHandler(sf::RenderWindow& window, sf::Event event);
virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
void update();
string getString();
void setPosition(float x, float y);
void setString(string str);
sf::Vector2f getBackPos();
bool empty();
sf::Rect<float> getGlobalBounds();
void clear();

private:
sf::Text _text;
MultiText multiText;
Letter str;
};


#endif //TYPING_TYPING_H
