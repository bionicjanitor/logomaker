//
// Created by zains on 3/6/2022.
//

#include "Letter.h"

Letter::Letter() {
    this->setString("");
    this->setCharacterSize(x);
    this->setFont(Fonts::getFont(Arial));
    this->setFillColor(sf::Color::Black);
}
