//
// Created by zains on 4/30/2022.
//

#include "ShadowDrop.h"

ShadowDrop::ShadowDrop() {
    mainText.setFont(Fonts::getFont(Arial));
    shadowText.setFont(Fonts::getFont(Arial));
    sf::FloatRect tb = mainText.getGlobalBounds();
    shadowText.setPosition(tb.left, tb.top + tb.height);
    shadowText.setScale(shadowText.getScale().x, -1);

    opacity = 50;
    setFillColor(sf::Color::White);
}

ShadowDrop::ShadowDrop(std::string text) {
    this->mainText.setString(text);
    this->shadowText.setString(text);

    sf::FloatRect tb = mainText.getGlobalBounds();
    shadowText.setPosition(tb.left, tb.top + tb.height);
                                            shadowText.setScale(shadowText.getScale().x, -1);
                                        }

void ShadowDrop::setOpacity(int opacity) {
    this->opacity = opacity;

}

void ShadowDrop::setPosition(sf::Vector2f position) {
    mainText.setPosition(position);
}

void ShadowDrop::setFillColor(sf::Color color) {
    mainText.setFillColor(color);
    color.a = opacity;
    shadowText.setFillColor(color);
}

void ShadowDrop::draw(sf::RenderTarget &window, sf::RenderStates &states) const {
    window.draw(mainText);
    states.transform = mainText.getTransform();
    window.draw(shadowText, states);
}
