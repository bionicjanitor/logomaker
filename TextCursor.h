//
// Created by zains on 3/26/2022.
//

#ifndef SFML_PROJECT_TEXTCURSOR_H
#define SFML_PROJECT_TEXTCURSOR_H

#include "SFML/Graphics.hpp"
#include "States.h"

using namespace std;

class TextCursor : public sf::Text {
public:
    TextCursor();
    void hideCursor();
    void enableCursor();
    void update();
    bool canType() const;

    void setPosition(sf::Vector2f vec);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

private:
    sf::RectangleShape cursor;
    sf::Clock clock;
    bool isEnabled;

};


#endif //SFML_PROJECT_TEXTCURSOR_H
