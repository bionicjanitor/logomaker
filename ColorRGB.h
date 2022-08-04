//
// Created by zains on 4/29/2022.
//

#ifndef LOGOMAKER_COLORRGB_H
#define LOGOMAKER_COLORRGB_H
#include "GuiComponentAdapter.h"

class ColorRGB : public GuiComponentAdapter {
private:
    sf::VertexArray gradients;
    sf::RectangleShape background;

    //int height, width;
    //int max, min;
    //int r, g, b;
    //int diff;
    //double H;

    //converting into rgb

    //double V, S;
    //int h;
    //double f, p, q, t;
    //int R, G, B;
public:
    ColorRGB();
    ColorRGB(sf::Color color);

    void setPosition(float x, float y);

    void setColor(sf::Color color);
    sf::Color getColor(sf::Vector2i position);
    sf::FloatRect getGlobalBounds();

    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

    //from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

    //from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);
};

#endif //LOGOMAKER_COLORRGB_H
