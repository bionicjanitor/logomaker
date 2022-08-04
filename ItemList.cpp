//
// Created by zains on 4/3/2022.
//
#include "ItemList.h"


ItemList::ItemList() {
   // cout << "itemList: " << __LINE__ << endl;
    isEnabled = false;
    for (int i = 0; i < 5; i++) {
        Item item = Item();
        item.setLabel("Label: " + to_string(i+1));
        pushback(item);
    }
}

ItemList::ItemList(float x, float y, int size) {
    //cout << "itemList: " << __LINE__ << endl;
    isEnabled = false;
    for (int i = 0; i < size; i++) {
        Item item = Item();
        item.setLabel("Label: " + to_string(i+1));
        _list.push_back(item);
    }
   // cout << "itemList: " << __LINE__ << endl;
    setPosition(x, y);
}


void ItemList::setPosition(float x, float y) {
    for (int i = 0; i < _list.size(); i++){
        _list[i].setPosition(x, y);
        y+=30;
    }
}



void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
//    if(MouseEvents<Item>::hovered(_list[0], window)){
//        _list[0].highlight();
//    }else{
//        _list[0].unhighlight();
//    }
    // cout << "ITEMLIST: " << __LINE__ << endl;
    vector<Item>::const_iterator item = _list.begin();
    for (auto &item : _list){
        // cout << "ITEMLIST: " << __LINE__ << endl;
        item.addEventHandler(window, event);
    }
    for(int i = 0; i < _list.size(); i++){
        if(MouseEvents<Item>::mouseClicked(_list[i], window)){
            States::disableState(DROPDOWN);
            States::enableState(CLICKED);
            enableList();
            label = _list[i].getLabel();
        }
    }
}


void ItemList::pushback(Item item) {
    _list.push_back(item);
    setPosition(_list.begin()->getPosition().x, _list.begin()->getPosition().y);
}


void ItemList::draw(sf::RenderTarget &window, sf::RenderStates states) const     {
    vector<Item>::const_iterator iter = _list.begin();
    for (auto &iter : _list){
        window.draw(iter);
    }
}

void ItemList::update() {
    cout << "itemList: " << __LINE__ << endl;
    if(listStatus()){
        if(States::checkState(HIDDEN)){
            //cout << "itemList: " << __LINE__ << endl;
            for(int i =0; i < _list.size(); i++){
                _list[i].setFillColorBox(sf::Color::Transparent);
                _list[i].setFillColorLabel(sf::Color::Transparent);
                States::disableState(HIDDEN);
            }
        }else{
            //cout << "itemList: " << __LINE__ << endl;
            for(int i =0; i < _list.size(); i++){
                _list[i].setFillColorBox(sf::Color::Black);
                _list[i].setFillColorLabel(sf::Color::White);
                States::enableState(HIDDEN);
            }
        }
    }
    cout << "itemList: " << __LINE__ << endl;
}


void ItemList::disableList() {
    isEnabled = false;
}


void ItemList::enableList() {
    isEnabled = true;
}

vector<Item> ItemList::getList() {
    return _list;
}

bool ItemList::listStatus() const {
    return isEnabled;
}

Item ItemList::operator[](int index) {
    return _list[index];
}

int ItemList::size() {
    return _list.size();
}

string ItemList::getLabel() {
    cout << "getting label " << endl;

    return label;
}

void ItemList::setLabels(vector<string> str) {
    for(int i = 0; i < str.size(); i++){
        _list[i].setLabel(str[i]);
    }
}
