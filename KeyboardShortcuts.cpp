//
// Created by zains on 3/24/2022.
//

#include "KeyboardShortcuts.h"

bool KeyboardShortcuts::isUndo() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z)){
        return true;
    }
    return false;
}
