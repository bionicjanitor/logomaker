//
// Created by zains on 3/22/2022.
//

#include "TextInput.h"

TextInput::TextInput() {
    Ti = Typing();
    textbox = TextBox();
    label.setFont(Fonts::getFont(Arial));
    label.setCharacterSize(12);
    label.setFillColor(sf::Color::White);
    cursor = TextCursor();
    isEnabled = true;
}

void TextInput::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(textbox);
    window.draw(label);
    window.draw(Ti);
    window.draw(cursor);
}

void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event)  {
    //cout << "TEXTINPUT: " << __LINE__ << endl;
    if(MouseEvents<TextBox>::mouseClicked(textbox, window))
    {
        enableCursor();
        cout << "LLLLL" << endl;
        std::cout << "textbox click" << std::endl;
    }
    else if(MouseEvents<TextBox>::mouseClicked(window, event) && !MouseEvents<TextBox>::hovered(textbox, window))
    {
        //disableCursor();
        cout << "TEXTINPUT: " << __LINE__ << endl;
        //std::cout << "window click" << std::endl;
    }
    if(isEnabled){
        //enableCursor();
        Ti.addEventHandler(window, event);
       // cout << "TEXTINPUT: " << __LINE__ << endl;
    }
    if(KeyboardShortcuts::isUndo())
    {
        std::cout << "undo!!" << std::endl;
    }
}


void TextInput::update() {
    cursor.update();
    cursor.setPosition({Ti.getBackPos().x+10, Ti.getBackPos().y-20});
}

void TextInput::setLabelSize(int size) {
    label.setCharacterSize(size);
}

void TextInput::setBoxSize(float width, float height) {
    textbox.setSize(width, height);
}

void TextInput::setPosition(sf::Vector2f vec) {
    if(vec.x < 50){
        label.setPosition(vec);
        textbox.setPosition(label.getGlobalBounds().width + 10, vec.y);
    }
    textbox.setPosition(vec.x, vec.y);
    cout << "textbox y: " << textbox.getPosition().y << endl;
    label.setPosition(vec.x-90, vec.y);
    cout << "label y: " << label.getPosition().y << endl;
    Ti.setPosition(vec.x, vec.y);
    cursor.setPosition(vec);
}

void TextInput::enableCursor() {
    isEnabled = true;
    cursor.enableCursor();
    States::enableState(HIDDEN);
    States::enableState(HIGHLIGHTED);
}

void TextInput::setLabel(string str) {
    label.setString(str);
}

void TextInput::disableCursor() {
    isEnabled = false;
    cursor.hideCursor();
    States::enableState(HIGHLIGHTED);
}

string TextInput::getString() {
    return Ti.getString();
}

sf::FloatRect TextInput::getGlobalBounds() const{
    return textbox.getGlobalBounds();
}

sf::Vector2f TextInput::getPosition() const{
    return textbox.getPosition();
}

void TextInput::setString(string str) {
    Ti.setString(str);
}

void TextInput::clear() {
    Ti.clear();
}
