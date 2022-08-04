//
// Created by zains on 5/1/2022.
//

#ifndef LOGOMAKER_SLIDER_H
#define LOGOMAKER_SLIDER_H
#include "GuiComponentAdapter.h"
#include "MouseEvents.h"
#include "SliderLabel.h"

class Slider : public GuiComponentAdapter {
public:
    Slider();
    Slider(float x, float y, string label, float linelength);

    void setKnob(float x, float y);
    void setLine(float x, float y);
    void setLineLength(float width);
    void setintPos(float x, float y);
    void enable();
    void disable();
    bool status();
    string getLabel();
    int getSliderVal();

    sf::Vector2f getKnobPos();
    int getLinePos(); //line.getGlobalBounds.width - knob.getPos

    sf::FloatRect getGlobalBounds() const;

    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

private:
    sf::CircleShape knob;
    sf::RectangleShape line;
    int linepos;
    sf::Text intpos;
    SliderLabel label;
    float length;
    bool isEnabled;
};

//class Slider : public GuiComponentAdapter {
//private:
//    sf::Text label;
//    sf::Text valLabel; //value of slider label
//    sf::RectangleShape slider;
//    sf::CircleShape knob;
//
//    int knobPos;
//    int padding = 10;
//public:
//    Slider();
//    Slider(std::string label);
//    Slider(std::string label, float size, float defaultValue = 0);
//
//    void setPosition(float x, float y);
//    void initialize();
//    void setLabel(std::string label);
//    void setLabelValue(float value);
//
//    std::string getLabel();
//    float getValueLabel();
//    sf::Vector2f getPosition();
//    sf::FloatRect getGlobalBounds();
//
//    //from the sf::Drawable class
//    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
//
//    //from EventHandler
//    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
//    virtual void update();
//
//    //from SnapshotInterface
//    virtual Snapshot& getSnapshot();
//    virtual void applySnapshot(const Snapshot& snapshot);
//};

#endif //LOGOMAKER_SLIDER_H
