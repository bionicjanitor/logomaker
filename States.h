//
// Created by zains on 3/21/2022.
//

#ifndef SFML_PROJECT_STATES_H
#define SFML_PROJECT_STATES_H

#include <iostream>
#include "map"

using namespace std;

enum ObjectState{
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    CLICKED,
    DROPDOWN,
    OUTLINE,
    CHILDREN,

    //sliders

    //menubar
    RESET,
    OPENPROJECT,
    CLOSEPROJECT,
    NEWPROJECT,
    SAVEPROJECT,
    QUIT,
    EXPORT,


    ///This should always be the last state
    LASTSTATE
};

enum Sliders{
    TEXTSLIDER,
    SHADOWSLIDER,
    FONTSLIDER,
    SKEW,
    TEXTY,
    SHADOWY,
    TEXTOPAC,
    BACKOPAC,
    FONTSIZE
};

class States {
public:
    States();

    States(Sliders sliders);

    static bool checkState(ObjectState state);
    static void enableState(ObjectState state);
    static void disableState(ObjectState state);
private:
    static map<ObjectState, bool> states;
};


#endif //SFML_PROJECT_STATES_H
