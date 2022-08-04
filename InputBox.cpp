//
// Created by zains on 4/3/2022.
//

#include "InputBox.h"

#include <utility>

InputBox::InputBox() {
    input = Item();
    input.setPosition(50, 0);
}

InputBox::InputBox(float x, float y){
    input = Item(x, y);
}

void InputBox::setLabel(string inputlabel) {
    input.setLabel(inputlabel);
}

void InputBox::setPosition(float x, float y) {
    input.setPosition(x, y);
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(input);
}

string InputBox::getLabel() {
    return input.getLabel();
}

sf::Rect<float> InputBox::getGlobalBounds() {
    return input.getGlobalBounds();
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<Item>::mouseClicked(input, window)){
        //cout << "mouse clicked" << endl;
        showList = true;
    }
}

bool InputBox::listShown() {
    return showList;
}
