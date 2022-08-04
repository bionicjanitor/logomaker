//
// Created by zains on 4/3/2022.
//

#ifndef SFML_PROJECT_ITEM_H
#define SFML_PROJECT_ITEM_H

#include "MouseEvents.h"
#include "GuiComponentAdapter.h"
#include "Fonts.h"


class Item : public GuiComponentAdapter {
public:
    Item();
    Item(float x, float y);
    void highlight();
    void unhighlight();
    void setLabel(string str);
    string getLabel();
    void setPosition(float x, float y);
    void setFillColorLabel(sf::Color color);
    void setFillColorBox(sf::Color color);
    void setSize(sf::Vector2f pos);
    sf::Vector2f getSize() const;
    sf::Vector2f getPosition() const;

    void update();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    sf::Rect<float> getGlobalBounds() const;

protected:
    sf::Text label;
    sf::RectangleShape box;
};


#endif //SFML_PROJECT_ITEM_H
