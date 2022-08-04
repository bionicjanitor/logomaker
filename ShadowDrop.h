//
// Created by zains on 4/30/2022.
//

#ifndef LOGOMAKER_SHADOWDROP_H
#define LOGOMAKER_SHADOWDROP_H


#include <SFML/Graphics.hpp>
#include "GuiComponentAdapter.h"
#include "Fonts.h"

class ShadowDrop : public GuiComponentAdapter{
private:
    sf::Text mainText;
    sf::Text shadowText;
    int opacity;
public:
    ShadowDrop();
    ShadowDrop(std::string text);

    void setOpacity(int opacity);
    void setPosition(sf::Vector2f position);
    void setFillColor(sf::Color color);
    virtual void draw(sf::RenderTarget &window, sf::RenderStates &states) const;

};


#endif //LOGOMAKER_SHADOWDROP_H
