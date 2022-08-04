//
// Created by zains on 4/29/2022.
//

#ifndef LOGOMAKER_LOGOMAKER_H
#define LOGOMAKER_LOGOMAKER_H

#include "DropMenu.h"
#include "MenuBar.h"
#include "TextInput.h"
#include "ColorPicker.h"
#include "ShadowDrop.h"
#include "FilenameWindow.h"
#include "Slider.h"
#include <map>

class LogoMaker : public GuiComponentAdapter {
public:
    LogoMaker();
    LogoMaker(float x, float y);
    void setPosition(float x, float y);

    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) ;
    virtual void update();

private:
    sf::RectangleShape background;
    sf::Text bigText;
    sf::Text shadow;
    sf::Texture texture;
    sf::Image source, image;
    int xPadding = 10;
    int yPadding = 30;
    bool newProj;

    DropMenu dropdown;
    MenuBar menuBar;
    TextInput input;
    ColorPicker picker;
    ColorPicker textcolor;
    //FilenameWindow filenameWindow;
    Slider shadowPos;
    Slider textPos;
    Slider textOpac;
    Slider backOpac;
    Slider textSize;
    Slider skew;
    Slider textY;
    Slider shadowY;
    vector<Slider> sliders;
    int index;
    sf::Text backlabel;
    sf::Text textLabel;
    bool projClose;
};


#endif //LOGOMAKER_LOGOMAKER_H
