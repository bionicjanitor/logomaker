//
// Created by zains on 3/6/2022.
//

#ifndef SFML_PROJECT_LETTER_H
#define SFML_PROJECT_LETTER_H

#include <SFML/Graphics.hpp>

#include "Fonts.h"

class Letter : public sf::Text{
public:
    Letter();
    int x = 20;

};


#endif //SFML_PROJECT_LETTER_H
