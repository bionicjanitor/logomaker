//
// Created by zains on 2/15/2022.
//

#include "Fonts.h"
std::map<FontNames, sf::Font> Fonts::fonts;

void Fonts::loadfont(FontNames fontName) {
    if(!fonts[fontName].loadFromFile(getFontPath(fontName))) {
        exit(28);
    }
}

std::string Fonts::getFontPath(FontNames fontName) {
    switch(fontName) {
        case Arial: return "../Fonts/Arial.ttf";
        case OPENSANSBOLD: return "../Fonts/OpenSans-Bold.ttf";
        case ARCADE: return "../Fonts/Arcade.tff";
        case WALTOGRAPH: return "../Fonts/waltographUI.ttf";
    }
}

sf::Font &Fonts::getFont(FontNames fontNames) {
    loadfont(fontNames);
    return fonts[fontNames];
}

