//
// Created by Chan Lee on 2022-04-30.
//

#include "FilenameTyper.h"
FilenameTyper::FilenameTyper()
{
    label.setString("Please enter name of file: ");
    label.setFillColor(sf::Color::Cyan);
    label.setCharacterSize(20);
    this->label.setFont(Fonts::getFont(OPENSANSBOLD));
}

void FilenameTyper::setPosition(sf::Vector2f pos)
{
    label.setPosition({pos.x, pos.y});
    textBox.setPosition(pos.x, label.getPosition().y + label.getGlobalBounds().height + 10);

    typing.setPosition(textBox.getPosition().x, textBox.getPosition().y+textBox.getOutlineThickness());
    //cursor.setPosition({pos.x,pos.y});

    cursor.setPosition({typing.getBackPos().x+5,textBox.getPosition().y+textBox.getOutlineThickness()});

    //cursor.setY(pos.y);
    //cursor.setPosition(multiText.getLastXPos(), cursor.getY());

    //cursor.setPosition(multiText.getLastXPos(), textBox.getPosition().y+textBox.getOutlineThickness());
    //multiText.setPosition({pos.x+textBox.getGlobalBounds().height, textBox.getPosition().y + textBox.getOutlineThickness()/2});
}

void FilenameTyper::enable()
{
    isEnable = true;
    cursor.enableCursor();
    States::enableState(HIDDEN);
    States::enableState(OUTLINE);
}
void FilenameTyper::disable()
{
    isEnable = false;
    cursor.enableCursor();
    States::disableState(OUTLINE);
}
bool FilenameTyper::checkEnable()
{
    return isEnable;
}
void FilenameTyper::setString(std::string string)
{
    typing.setString(string);
}

void FilenameTyper::setLength(float len)
{
    textBox.setSize(len, textBox.getSize().y);
}
void FilenameTyper::setSize(float x, float y)
{
    textBox.setSize(x, y);
}

std::string FilenameTyper::getString()
{
    return typing.getString();
}

sf::FloatRect FilenameTyper::getGlobalBound()
{
    return textBox.getGlobalBounds();
}

void FilenameTyper::addEventHandler(sf::RenderWindow& window, sf::Event event)
{
    //HistoryNode h ={this, getSnapshot()};
    //History::push(h);
    //History::top().component->applySnapshot(History::top().snapshot);
    if(MouseEvents<TextBox>::mouseClicked(textBox, window))
    {
        enable();
        std::cout << "textbox click" << std::endl;
    }
    else if(MouseEvents<TextBox>::mouseClicked(window, event) && !MouseEvents<TextBox>::hovered(textBox, window))
    {
        disable();
        std::cout << "window click" << std::endl;
    }
    if(isEnable)
    {
        typing.addEventHandler(window, event);
    }
}
void FilenameTyper::update()
{
    if(States::checkState(OUTLINE))
    {
        textBox.setOutlineThickness(2);
    }
    else
    {
        textBox.setOutlineThickness(1);
    }
    if(isEnable)
    {
        cursor.setPosition({typing.getBackPos().x, textBox.getPosition().y+textBox.getOutlineThickness()});
        cursor.update();
    }
}
void FilenameTyper::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    window.draw(textBox);
    window.draw(label);
    window.draw(multiText);
    if(isEnable)
    {
        window.draw(cursor);
    }
}

