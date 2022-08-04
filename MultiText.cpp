//
// Created by zains on 3/6/2022.
//
#include "MultiText.h"

MultiText::MultiText() {
    x = 0;
    y = 0;
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto &iter : letters){
        window.draw(iter);
//        states.transform = iter.getTransform();
//        window.draw(iter, states);
    }
}


list<Letter>::iterator MultiText::begin() {
    return letters.begin();
}


list<Letter>::iterator MultiText::end() {
    return letters.end();
}

list<Letter> MultiText::getList() {
    return letters;
}

void MultiText::push_back(char cha) {
    if(!letters.empty()) {
        letter.setString(cha);
        letter.setPosition({letters.back().getGlobalBounds().left + letters.back().getGlobalBounds().width, letters.back().getPosition().y});
        cout << "letter back y: " << letters.back().getPosition().y << endl;
        cout << "letter back x: " << letters.back().getPosition().x << endl;
        if (letters.back().getPosition().x > 305) {
            letter.setPosition({letters.begin()->getGlobalBounds().left, letters.back().getPosition().y + 20});
            letters.push_back(letter);
        }
        letters.push_back(letter);
    }else{
        letter.setPosition(20, 470);
        cout << "letter begin y: " << letters.begin()->getPosition().y << endl;
        letter.setString(cha);
        letters.push_back(letter);
    }

}

void MultiText::pop() {
    if(!letters.empty()){
        letters.pop_back();
        letter.setPosition(letters.back().getPosition().x-10, letters.back().getPosition().y);
    }
}

void MultiText::space(){
    letter.setString(" ");
    letter.setPosition({letters.back().getGlobalBounds().left + letters.back().getGlobalBounds().width, letters.back().getPosition().y});
    letters.push_back(letter);
}

void MultiText::enter() {
    letter.setString("");
    letter.setPosition({0, letters.back().getPosition().y +20});
    letters.push_back(letter);
}

void MultiText::setPosition(float x, float y) {
    letters.begin()->setPosition({x, y});
    cout << letters.begin()->getPosition().y << endl;
}

bool MultiText::empty() {
    return letters.empty();
}

sf::Vector2f MultiText::getBackPos() {
    return letters.back().getPosition();
}

string MultiText::getString() {
    string temp;
    for (auto &iter : letters) {
        temp += iter.getString();
    }
    return temp;
}

void MultiText::setString(string str) {
    while(!letters.empty()){
        letters.pop_front();
    }
    for (int i = 0; i < str.length(); i++){
       push_back(str.at(i));
    }
}

void MultiText::clear() {
    while(!letters.empty()){
        letters.pop_front();
    }
}
