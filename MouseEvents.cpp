//
// Created by zains on 3/22/2022.
//

#ifndef SFML_PROJECT_MOUSEEVENTS_CPP
#define SFML_PROJECT_MOUSEEVENTS_CPP

#include "MouseEvents.h"

template<class T>
int MouseEvents<T>::clicks;

template<class T>
sf::Clock MouseEvents<T>::clock;

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    if(hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)){
        if(clock.getElapsedTime().asSeconds() <= 0.5){
            clicks++;
            clock.restart();
        }else{
            clicks = 0;
            clock.restart();
        }
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left){
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(clicks == 2){
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks == 3){
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (event.type != event.MouseButtonReleased && event.type == event.MouseMoved) {
            return true;
        }
    }
    return false;
}

template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f vec = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    if(object.getGlobalBounds().contains(vec.x, vec.y)){
        return true;
    }
    return false;
}

template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    if(mouseClicked(event)){
        clicks++;
    }
}


#endif