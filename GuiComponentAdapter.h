//
// Created by zains on 3/24/2022.
//

#ifndef SFML_PROJECT_GUICOMPONENTADAPTER_H
#define SFML_PROJECT_GUICOMPONENTADAPTER_H

#include "GuiComponent.h"

class GuiComponentAdapter : public GuiComponent {
public:
    //from the sf::Drawable class
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;

// from EventHandler
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    virtual void update();

//from SnapshotInterface
    virtual Snapshot& getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

};


#endif //SFML_PROJECT_GUICOMPONENTADAPTER_H
