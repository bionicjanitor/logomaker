//
// Created by Chan Lee on 2022-04-30.
//

#ifndef LOGOMAKER_FILENAMETYPER_H
#define LOGOMAKER_FILENAMETYPER_H
#include "GUIComponent.h"
#include <SFML/Graphics.hpp>
#include "MultiText.h"
#include "MouseEvents.h"
#include "History.h"
#include "TextCursor.h"
#include "TextBox.h"
#include "Typing.h"
#include "GuiComponentAdapter.h"

class FilenameTyper : public GuiComponentAdapter{
private:
    TextBox textBox;
    MultiText multiText;
    TextCursor cursor;
    Typing typing;
    sf::Text label;
    bool isEnable;
public:
    FilenameTyper();

    void enable();
    void disable();
    bool checkEnable();

    void setPosition(sf::Vector2f pos);
    void setString(std::string string);
    void setFont(FontNames font);
    void setSize(float x, float y);
    void setLength(float len);

    std::string getString();
    sf::FloatRect getGlobalBound();

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

};


#endif //LOGOMAKER_FILENAMETYPER_H
