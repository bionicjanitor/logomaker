//
// Created by zains on 3/22/2022.
//

#ifndef SFML_PROJECT_TEXTINPUT_H
#define SFML_PROJECT_TEXTINPUT_H
#include "Typing.h"
#include "GuiComponentAdapter.h"
#include "History.h"
#include "States.h"
#include "KeyboardShortcuts.h"
#include "TextBox.h"
#include "TextCursor.h"
#include "MouseEvents.h"
#include "TextLabel.h"

class TextInput : public GuiComponentAdapter {
public:
    TextInput();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) ;
    virtual void update();
    void setLabel(string str);
    void setLabelSize(int size);
    void setBoxSize(float width, float height);
    void setPosition(sf::Vector2f vec);
    void enableCursor();
    void disableCursor();
    string getString();
    void setString(string str);
    void clear();

    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const;
private:
    Typing Ti;
    TextCursor cursor;
    TextBox textbox;
   // TextLabel label;
    sf::Text label;
    bool isEnabled;
};


#endif //SFML_PROJECT_TEXTINPUT_H
