//
// Created by zains on 3/26/2022.
//

#include "TextLabel.h"

TextLabel::TextLabel() {
    text.setFont(Fonts::getFont(Arial));
    text.setCharacterSize(12);
    text.setFillColor(sf::Color::White);
}

void TextLabel::draw(sf::RenderTarget &window, sf::RenderStates states) {
    window.draw(text);
}
