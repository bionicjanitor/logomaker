//
// Created by zains on 3/22/2022.
//

#ifndef SFML_PROJECT_HISTORY_H
#define SFML_PROJECT_HISTORY_H

#include "GuiComponentAdapter.h"
#include <stack>

using namespace std;

struct HistoryNode
{
    Snapshot snapshot;
    GuiComponent* component;
};

class History  {
private:
    static stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};




#endif //SFML_PROJECT_HISTORY_H
