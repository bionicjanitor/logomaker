//
// Created by zains on 4/3/2022.
//

#include "DropMenu.h"

DropMenu::DropMenu() {
    int x = 100;
    int y = 100;
    input = InputBox(x, y);
    _list = ItemList(x, y+30, 4);
    _list.setLabels({"Arial", "OpenSansBold", "Arcade", "Waltograph"});
    input.setLabel(_list[0].getLabel());
    //isClicked = false;
}

DropMenu::DropMenu(float x, float y) {
    input = InputBox(x, y);
    _list = ItemList(x, y+30, 4);
    _list.setLabels({"Arial", "OpenSansBold", "Arcade", "Waltograph"});
    input.setLabel(_list[0].getLabel());
    //isClicked = false;
}

void DropMenu::update() {
    if(States::checkState(CLICKED)){
        //History::pushHistory(*h);
        input.setLabel(_list.getLabel());
        States::disableState(CLICKED);
    }
}

void DropMenu::addItem(string data) {
    Item temp = Item();
    temp.setLabel(data);
    _list.pushback(temp);
}

void DropMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    int clicked = 0; //int to keep track of how many times the menu was clicked
    input.addEventHandler(window, event);
    //use dropdown state to add the event handler for the itemlist
    if(States::checkState(DROPDOWN)){
        _list.addEventHandler(window, event);
    }
    if(MouseEvents<InputBox>::mouseClicked(input, window)){
        //cout << "LLLLL" << endl;
        if(States::checkState(DROPDOWN)){
            States::disableState(DROPDOWN);
        }else{
            States::enableState(DROPDOWN);
        }

    }


    //use apply snapshot to undo

}

void DropMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(input);
    if(States::checkState(DROPDOWN)){
        window.draw(_list);
    }
}

Snapshot &DropMenu::getSnapshot() {
    snapshot.data = input.getLabel();
    return snapshot;
}

void DropMenu::applySnapshot(const Snapshot &snapshot) {
    input.setLabel(snapshot.data);
}

string DropMenu::getLabel() {
    return input.getLabel();
}
