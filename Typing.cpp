//
// Created by zains on 2/21/2022.
//
#ifndef TYPING_TYPING_CPP
#define TYPING_TYPING_CPP
#include <iostream>
#include <string.h>
#include "Typing.h"

using namespace std;

Typing::Typing() {
    _text.setFont(Fonts::getFont(Arial));
    _text.setCharacterSize(10);
    _text.setString("");

}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::TextEntered){
        //cout << "start " << endl;
        if(event.text.unicode < 128 && event.text.unicode > 31){
            multiText.push_back(static_cast<char>(event.text.unicode));
            cout << event.text.unicode << endl;
        }
        else if(event.text.unicode == 8){
            cout << "pop: " << event.text.unicode << endl;
            multiText.pop();
        }
//        else if(event.text.unicode == 32){
//            multiText.space();
//        }
        else if(event.text.unicode == 13){
           // cout << "enter: " << event.text.unicode << endl;
           multiText.enter();
        }
       // cout << "end" << endl;
    }

}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(multiText);
//    states.transform = multiText.getTransform();
//    window.draw(multiText, states);
}

void Typing::update() {

}

void Typing::setPosition(float x, float y) {
    multiText.setPosition(x, y);
}



sf::Rect<float> Typing::getGlobalBounds() {
    sf::Rect<float> r;
    r.left = multiText.begin()->getGlobalBounds().left;
    r.top = multiText.begin()->getGlobalBounds().top;
    r.width = (multiText.end()->getGlobalBounds().left - multiText.begin()->getGlobalBounds().left);
    r.height = multiText.end()->getGlobalBounds().height;
    return r;
}

bool Typing::empty() {
    return multiText.empty();
}

sf::Vector2f Typing::getBackPos() {
    return multiText.getBackPos();
}

string Typing::getString() {
   return multiText.getString();
}

void Typing::setString(string str) {
    multiText.setString(str);
}

void Typing::clear() {
    multiText.clear();
}

#endif