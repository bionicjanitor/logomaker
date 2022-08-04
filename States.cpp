//
// Created by zains on 3/21/2022.
//

#include "States.h"

map<ObjectState, bool> States::states;

States::States() {
    for(int i=0; i<LASTSTATE; i++)
    {
        states[ObjectState(i)] = false;
    }
}

bool States::checkState(ObjectState state) {
    return states[state];
}

void States::enableState(ObjectState state) {
    states[state] = true;
}

void States::disableState(ObjectState state) {
    states[state] = false;
}


