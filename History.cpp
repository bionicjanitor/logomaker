//
// Created by zains on 3/22/2022.
//


#include "History.h"
stack<HistoryNode> History::stack;
void History::pushHistory(const HistoryNode &snapshot) {
    stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}
