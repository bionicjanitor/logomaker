//
// Created by zains on 3/26/2022.
//

#include "TextBox.h"

TextBox::TextBox() {
    cout << "TEXTBOX: " << __LINE__ << endl;
    rect.setOutlineColor(sf::Color::Black);
    rect.setFillColor(sf::Color::White);
//    rect.setSize({200, 20});
    rect.setOutlineThickness(5);
}

void TextBox::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(rect);
}

void TextBox::setPosition(float x, float y) {
    rect.setPosition(x, y);
}

sf::Vector2f TextBox::getPosition() const {
    return rect.getPosition();
}

void TextBox::setSize(float x, float y) {
    rect.setSize({x, y});
}
