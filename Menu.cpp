//
// Created by zains on 4/18/2022.
//

#include "Menu.h"

Menu::Menu() {
    isEnabled = false;
    title = Item();
    menu = ItemList(title.getPosition().x, title.getPosition().y+30, 1);
}

Menu::Menu(float x, float y, int size) {
    isEnabled = false;
    title = Item(x, y);
    menu = ItemList(x, y+30, size);
}

void Menu::setLabel(string label) {
    title.setLabel(label);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(isEnabled){
        menu.addEventHandler(window, event);
    }

    if(MouseEvents<Item>::mouseClicked(title, window)){
        if(isEnabled){
            isEnabled = false;
            title.unhighlight();
        }else{
            isEnabled = true;
            title.highlight();
        }
    }
    auto iter = menu.getList().cbegin();
    for(auto &iter: menu.getList()) {
        if (MouseEvents<Item>::mouseClicked(iter, window)) {
            isEnabled = false;
            title.unhighlight();
            listlabel = iter.getLabel();
        }
    }

    if (listlabel == "Close Project"){
        States::enableState(CLOSEPROJECT);
    }

    if(listlabel == "Open Project"){
        States::enableState(OPENPROJECT);
    }

    if(listlabel == "New Project"){
        States::enableState(NEWPROJECT);
    }

    if(listlabel == "Save Project"){
        States::enableState(SAVEPROJECT);
    }

    if(listlabel == "Quit"){
        States::enableState(QUIT);
    }

    if(listlabel == "Export"){
        States::enableState(EXPORT);
    }

//    if(MouseEvents<Item>::mouseClicked(window, event)){
//        disableList();
//        title.unhighlight();
//    }
}

void Menu::setPosition(float x, float y) {
    title.setPosition(x,y);
    menu.setPosition(x, y+30);
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(title);
    if(isEnabled){
        window.draw(menu);
    }
}

sf::Rect<float> Menu::getGlobalBounds() {
    return title.getGlobalBounds();
}

void Menu::disableList() {
    menu.disableList();
}

void Menu::enableList() {
    menu.enableList();;
}

bool Menu::listStatus() {
    return menu.listStatus();
}

vector<Item> Menu::getList() {
    return menu.getList();
}

void Menu::setLabels(vector<string> strings) {
    menu.setLabels(strings);
}
