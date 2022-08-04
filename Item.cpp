//
// Created by zains on 4/3/2022.
//

#include "Item.h"


Item::Item() {
    box.setSize({300, 30});
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(1);
    box.setPosition(0,0);
    label.setString("Label");
    label.setFont(Fonts::getFont(Arial));
    label.setCharacterSize(16);
    label.setPosition( box.getPosition().x + box.getSize().x/2.8 , box.getPosition().y  + 5);
}

Item::Item(float x, float y) {
    box.setSize({300, 30});
    box.setFillColor(sf::Color::Black);
    box.setOutlineColor(sf::Color::White);
    box.setOutlineThickness(1);
    box.setPosition(x, y);
    label.setString("Label");
    label.setFont(Fonts::getFont(Arial));
    label.setCharacterSize(16);
    label.setPosition(box.getPosition().x + box.getSize().x/2.8 , box.getPosition().y  + 5);
    //setPosition(x, y);
}


void Item::highlight() {
    box.setFillColor(sf::Color::Blue);
    label.setStyle(sf::Text::Bold);

}


void Item::update() {

}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box, window)){
        //cout << "hovering" << endl;
        highlight();
    }else{
        unhighlight();
    }
    if(MouseEvents<sf::RectangleShape>::mouseClicked(box, window)){
        if(States::checkState(CLICKED)){
            unhighlight();
            States::disableState(CLICKED);
        }else{
            States::enableState(CLICKED);
            highlight();
        }
    }
}

void Item::unhighlight() {
    box.setFillColor(sf::Color::Black);
    label.setStyle(sf::Text::Regular);
}

void Item::setLabel(string str) {
    label.setString(str);
    //cout << "item.x: " << box.getPosition().x << endl;
}

void Item::setPosition(float x, float y){
    box.setPosition(x , y);
    label.setPosition(box.getPosition().x + box.getSize().x/2.8 , box.getPosition().y  + 5);
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(box);
    window.draw(label);
}

sf::Rect<float> Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void Item::setFillColorLabel(sf::Color color) {
    label.setFillColor(color);
}

void Item::setFillColorBox(sf::Color color) {
    box.setFillColor(color);
}

string Item::getLabel() {
    return label.getString();
}

sf::Vector2f Item::getSize() const {
    return box.getSize();
}

sf::Vector2f Item::getPosition() const {
    return box.getPosition();
}

void Item::setSize(sf::Vector2f pos) {
    box.setSize(pos);
}
