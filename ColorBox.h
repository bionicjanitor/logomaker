//
// Created by zains on 4/29/2022.
//

#ifndef LOGOMAKER_COLORBOX_H
#define LOGOMAKER_COLORBOX_H
#include <SFML/Graphics.hpp>

class ColorBox : public sf::RectangleShape {
public:
    ColorBox();
    ColorBox(sf::Color color);

    void setColor(sf::Color color);
    sf::Color getColor() const;
};


#endif //LOGOMAKER_COLORBOX_H
