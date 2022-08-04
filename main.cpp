#include <iostream>
#include "LogoMaker.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800, 32), "Test");
    LogoMaker logo = LogoMaker();
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            logo.addEventHandler(window, event);
        }
        logo.update();

        window.clear(sf::Color::Black);
        window.draw(logo);
        //window.draw(menuBar);
        window.display();
    }
    return 0;
}
