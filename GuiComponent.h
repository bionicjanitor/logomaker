//
// Created by zains on 3/21/2022.
//

#ifndef SFML_PROJECT_GUICOMPONENT_H
#define SFML_PROJECT_GUICOMPONENT_H

#include "States.h"
#include "SnapshotInterface.h"
#include "EventHandler.h"


class GuiComponent : public SnapshotInterface, public States, public EventHandler, public sf::Drawable, public sf::Transformable{
//from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const = 0;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;

//from SnapshotInterface
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};



#endif //SFML_PROJECT_GUICOMPONENT_H
