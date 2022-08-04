//
// Created by zains on 5/1/2022.
//

#include "Slider.h"

Slider::Slider() {
    label = SliderLabel();
    isEnabled = false;
}

Slider::Slider(float x, float y, string label, float linelength) {
    isEnabled = false;
    linepos = 0;
    this->label = SliderLabel();
    this->label.setString(label);
    this->label.setPosition(x, y);
    line.setSize({9,  linelength});
    line.setFillColor(sf::Color::White);
    line.setPosition(x + this->label.getGlobalBounds().width + 10, y+ this->label.getGlobalBounds().height);
    knob.setRadius(10);
    knob.setOrigin({10, 0});
    knob.setFillColor(sf::Color::White);
    knob.setPosition(line.getPosition().x, y+ this->label.getGlobalBounds().height/2);
    intpos.setFont(Fonts::getFont(Arial));
    intpos.setPosition(line.getPosition().x + linelength + 10, y);
    intpos.setString(to_string(linepos));
    intpos.setCharacterSize(20);
}

void Slider::setKnob(float x, float y) {
    knob.setPosition(x, y);
}

void Slider::setLine(float x, float y) {
    line.setPosition(x, y);
}

sf::Vector2f Slider::getKnobPos() {
    return knob.getPosition();
}

void Slider::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::CircleShape>::mouseClicked(knob, window)){
        enable();
    }
    if(isEnabled){
        if(MouseEvents<sf::CircleShape>::draggedOver(knob, window, event)){
            linepos = knob.getPosition().x - line.getGlobalBounds().left;
            sf::Vector2f mousepos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            knob.setPosition(mousepos.x - knob.getGlobalBounds().width/2, knob.getPosition().y);
            if(mousepos.x > line.getPosition().x + line.getSize().x){
                knob.setPosition(line.getPosition().x + line.getSize().x, knob.getPosition().y);
            }
            if(mousepos.x < line.getPosition().x){
                knob.setPosition(line.getPosition().x, knob.getPosition().y);
            }
            intpos.setString(to_string(linepos));
        }

    }
}

void Slider::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(label);
    window.draw(line);
    window.draw(knob);
    window.draw(intpos);
}

void Slider::update() {

}

int Slider::getLinePos() {
    return linepos;
}

void Slider::setLineLength(float width) {
    length = width;
    line.setSize({length, 3});
}

void Slider::setintPos(float x, float y) {
    intpos.setPosition(x, y);
}

void Slider::enable() {
    isEnabled = true;
}

void Slider::disable() {
    isEnabled = false;
}

bool Slider::status() {
    return isEnabled;
}

sf::FloatRect Slider::getGlobalBounds() const{
    return knob.getGlobalBounds();
}

string Slider::getLabel() {
    return label.getString();
}

int Slider::getSliderVal() {
    return linepos;
}
