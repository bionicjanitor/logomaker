//
// Created by zains on 3/6/2022.
//

#ifndef SFML_PROJECT_MULTITEXT_H
#define SFML_PROJECT_MULTITEXT_H
#include <list>
#include "Letter.h"
#include "TextBox.h"
#include <iterator>

#include <iostream>

using namespace std;

class MultiText : public sf::Drawable, public sf::Transformable{
public:
    MultiText();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    list<Letter> getList();


    list<Letter>::iterator begin();
    list<Letter>::iterator end();

    void push_back(char cha);
    void space();
    void enter();
    void pop();
    string getString();
    void setPosition(float x, float y);
    sf::Vector2f getBackPos();
    bool empty();
    void setString(string str);
    void clear();
private:
    list<Letter> letters;
    Letter letter;
    _List_const_iterator<Letter> iter = letters.begin();
    float x;
    float y;
    TextBox textbox;
};


#endif //SFML_PROJECT_MULTITEXT_H
