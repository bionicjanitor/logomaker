//
// Created by zains on 4/18/2022.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
    for (int i = 0; i < 3; i++) {
        Menu menu = Menu();
        switch (i) {
            case 0:
                menu.setLabel("File");
                break;
            case 1:
                menu.setLabel("Edit");
                break;
            case 2:
                menu.setLabel("Render");
                break;
        }
        list.push_back(menu);
    }

    setPostition(0,0);
}

MenuBar::MenuBar(float x, float y) {
    Menu file = Menu(0, 0, 5);
    Menu edit = Menu(0, 0, 2);
    Menu Render = Menu(0, 0, 1);
    for (int i = 0; i < 3; i++) {
        switch (i) {
            case 0:
                file.setLabel("File");
                file.setLabels({"Close Project", "New Project", "Open Project", "Quit", "Save Project"});
                list.push_back(file);
                break;
            case 1:
                edit.setLabel("Edit");
                edit.setLabels({"undo", "redo"});
                list.push_back(edit);
                break;
            case 2:
                Render.setLabel("Render");
                Render.setLabels({"Export"});
                list.push_back(Render);
                break;
        }

    }
    setPostition(x,y);
}

void MenuBar::pushback(string label) {
    number++;
    Menu menu = Menu();
    menu.setLabel(label);
    if(list.empty()){
        list.push_back(menu);
    }else{
        menu.setPosition(list.back().getGlobalBounds().left + list.back().getGlobalBounds().width, list.back().getPosition().y);
        list.push_back(menu);
        cout << "list.back().x: " << list.back().getPosition().x << endl;
    }
}

void MenuBar::setLabel(int position, string label) {
    list[position].setLabel(label);
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    vector<Menu>::const_iterator menu = list.begin();
    for(auto &menu: list){
        //if(MouseEvents<Menu>::mouseClicked(menu, window)){
            menu.addEventHandler(window, event);
       // }
    }
//    for (int i = 0; i < list.size(); i++) {
//        if(MouseEvents<Menu>::mouseClicked(list[i], window)){
//            list[0].addEventHandler(window, event);
//        }
//    }
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    vector<Menu>::const_iterator menu = list.begin();
    for(auto &menu: list){
        window.draw(menu);
    }
}

void MenuBar::setPostition(float x, float y) {
    for (int i = 0; i < list.size(); i++) {
        list[i].setPosition(x, y);
        cout << x << endl;
        x+=300;
    }
}

sf::FloatRect MenuBar::getGlobalBounds() {
    for(int i = 0; i < list.size(); i++)
    {
        sf::FloatRect rect;
        rect.left = list.at(i).getPosition().x;
        rect.width = list.at(i).getGlobalBounds().width;
        rect.top = list.at(i).getPosition().y;
        rect.height = list.at(i).getGlobalBounds().height;
        return rect;
    }
}
