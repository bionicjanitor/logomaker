//
// Created by zains on 4/3/2022.
//

#ifndef SFML_PROJECT_ITEMLIST_H
#define SFML_PROJECT_ITEMLIST_H
#include "Item.h"
#include "MouseEvents.h"
#include "vector"
#include "States.h"
#include "list"


class ItemList : public GuiComponentAdapter {
public:
    ItemList();
    ItemList(float x, float y, int size);
    void pushback(Item item);
    void setPosition(float x, float y);
    vector<Item> getList();
    string getLabel();

    void setLabels (vector<string> str);
    void disableList();
    void enableList();
    bool listStatus() const;
    int size();

    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void update();

    Item operator [](int index);



private:
    bool isEnabled;
    string label;
    vector<Item> _list;
};




#endif //SFML_PROJECT_ITEMLIST_H
