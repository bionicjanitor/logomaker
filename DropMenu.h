//
// Created by zains on 4/3/2022.
//

#ifndef SFML_PROJECT_DROPMENU_H
#define SFML_PROJECT_DROPMENU_H

#include "InputBox.h"
#include "History.h"
#include "KeyboardShortcuts.h"

class DropMenu : public GuiComponentAdapter {
public:
    DropMenu();
    DropMenu(float x, float y);

    void addItem(string data);

    void update();
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    string getLabel();
    Snapshot& getSnapshot();
    void applySnapshot(const Snapshot& snapshot);

private:
    InputBox input;
    ItemList _list;
    Snapshot snapshot;
    HistoryNode* h;
    bool isClicked;
};


#endif //SFML_PROJECT_DROPMENU_H
