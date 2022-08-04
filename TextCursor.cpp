//
// Created by zains on 3/26/2022.
//

#include "TextCursor.h"

TextCursor::TextCursor() {
    cursor.setSize({2, 35});
    cursor.setFillColor(sf::Color::White);

    clock.restart();
}

void TextCursor::update() {
    if(isEnabled){
        if(clock.getElapsedTime().asSeconds() >= 0.5){
            clock.restart();
            if(States::checkState(HIDDEN)){
                cursor.setFillColor(sf::Color::Transparent);
                cursor.setOutlineColor(sf::Color::Transparent);
                States::disableState(HIDDEN);
            }
            else{
                cursor.setFillColor(sf::Color::Black);
                States::enableState(HIDDEN);
            }
        }
    }
}

void TextCursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(canType()){
        window.draw(cursor);
    }
}

void TextCursor::hideCursor() {
    isEnabled = false;
}

void TextCursor::enableCursor() {
    isEnabled = true;
}

bool TextCursor::canType() const {
    return isEnabled;
}

void TextCursor::setPosition(sf::Vector2f vec) {
    cursor.setPosition(vec);
}
