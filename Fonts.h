//
// Created by zains on 2/15/2022.
//

#ifndef SFML_PROJECT_FONTS_H
#define SFML_PROJECT_FONTS_H

#include <map>
#include "FontNames.h"
#include <SFML/Graphics.hpp>

using namespace std;

class Fonts {
public:
    static sf::Font& getFont(FontNames fontname);

private:
    static map<FontNames, sf::Font> fonts;
    static void loadfont(FontNames fontname);
    static string getFontPath(FontNames fontname);
};


#endif //SFML_PROJECT_FONTS_H
