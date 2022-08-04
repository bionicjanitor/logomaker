//
// Created by zains on 5/1/2022.
//

#include "SliderLabel.h"

SliderLabel::SliderLabel() {
    label.setFont(Fonts::getFont(Arial));
    label.setCharacterSize(20);
}

void SliderLabel::setString(string str) {
    label.setString(str);
}

void SliderLabel::setPosition(float x, float y) {
    label.setPosition(x, y);
}

sf::Vector2f SliderLabel::getPos() const{
    return label.getPosition();
}

void SliderLabel::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
}

sf::FloatRect SliderLabel::getGlobalBounds() const {
    return label.getGlobalBounds();
}

string SliderLabel::getString() {
    return label.getString();
}
