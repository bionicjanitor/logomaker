//
// Created by zains on 3/26/2022.
//

#ifndef SFML_PROJECT_TEXTLABEL_H
#define SFML_PROJECT_TEXTLABEL_H

#include <SFML/Graphics.hpp>
#include "GuiComponentAdapter.h"
#include "Fonts.h"

class TextLabel : public sf::Text {
public:
    TextLabel();
    void draw(sf::RenderTarget& window, sf::RenderStates states);

private:
    sf::Text text;
};


#endif //SFML_PROJECT_TEXTLABEL_H
