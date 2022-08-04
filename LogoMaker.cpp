//
// Created by zains on 4/29/2022.
//

#include "LogoMaker.h"

LogoMaker::LogoMaker() {
    picker = ColorPicker();
    picker.setPosition(500, 450);

    backlabel.setFont(Fonts::getFont(Arial));
    backlabel.setFillColor(sf::Color::White);
    backlabel.setCharacterSize(16);
    backlabel.setStyle(sf::Text::Bold);
    backlabel.setPosition(350, 450);
    backlabel.setString("Background color: ");

    textcolor = ColorPicker();
    textcolor.setPosition(955, 450);
    textcolor.setColor(sf::Color::White);

    bigText.setFont(Fonts::getFont(Arial));
    bigText.setFillColor(sf::Color::White);
    bigText.setCharacterSize(100);
    bigText.setStyle(sf::Text::Bold);
    bigText.setPosition(200, 150);

    textLabel.setFont(Fonts::getFont(Arial));
    textLabel.setFillColor(sf::Color::White);
    textLabel.setPosition(860, 450);
    textLabel.setStyle(sf::Text::Bold);
    textLabel.setCharacterSize(16);
    textLabel.setString("Text Color: ");

    sf::FloatRect tb = bigText.getGlobalBounds();
    shadow.setFont(Fonts::getFont(Arial));
    shadow.setFillColor(sf::Color::White);
    shadow.setCharacterSize(100);
    shadow.setPosition(bigText.getPosition().x, bigText.getPosition().y+20);
    shadow.setScale(shadow.getScale().x, -0.5);

    background.setSize({1200, 400});
    background.setPosition(0,0);
    background.setFillColor(sf::Color::Black);

    dropdown = DropMenu(550, 450);
    menuBar = MenuBar(0,0);

    input = TextInput();
    input.setPosition({20, 450});
    input.setBoxSize(300, 40);

    textPos = Slider(10, 500, "Text Position: ", 900);
    textPos.setLineLength(900);
    sliders.push_back(textPos);

    shadowPos = Slider(10, 550, "Shadow Pos: ", 900);
    shadowPos.setLineLength(900);
    sliders.push_back(shadowPos);

    textOpac = Slider(10, 600, "Text Opacity: ", 255);
    textOpac.setLineLength(255);
    sliders.push_back(textOpac);

    textSize = Slider(450, 600, "Font Size: ", 125);
    textSize.setLineLength(125);
    sliders.push_back(textSize);

    skew = Slider(1000, 450, "Skew: ", 100);
    skew.setLineLength(100);
    sliders.push_back(skew);

    backOpac = Slider(725, 600, "Back Opac: ", 255);
    backOpac.setLineLength(255);
    sliders.push_back(backOpac);

    textY = Slider(10, 650, "Text Y Pos: ", 900);
    textY.setLineLength(900);
    sliders.push_back(textY);

    shadowY = Slider(10, 700, "Shadow Y Pos: ", 900);
    shadowY.setLineLength(900);
    sliders.push_back(shadowY);

}

LogoMaker::LogoMaker(float x, float y) {

}

void LogoMaker::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!projClose){
        window.draw(background);
        window.draw(input);
        states.transform = bigText.getTransform();
        window.draw(shadow, states);
        window.draw(bigText);
        window.draw(textLabel);
        window.draw(backlabel);
        for (auto &iter: sliders) {
            window.draw(iter);
        }
        window.draw(picker);
        window.draw(textcolor);
        window.draw(dropdown);
    }
    window.draw(menuBar);
//    window.draw(textPos);
//    window.draw(shadowPos);
//    window.draw(textOpac);
//    window.draw(textSize);
//    window.draw(skew);
//    window.draw(backOpac);
//    window.draw(textY);
//    window.draw(shadowY);

}

void LogoMaker::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    input.addEventHandler(window, event);
    menuBar.addEventHandler(window, event);
    dropdown.addEventHandler(window, event);
    picker.addEventHandler(window, event);
    textcolor.addEventHandler(window, event);

    if(MouseEvents<TextInput>::mouseClicked(input, window)){
        input.enableCursor();
    }

    for (int j = 0; j < sliders.size(); j++) {
    }
//        if (MouseEvents<Slider>::draggedOver(sliders[j], window, event)) {
//            string temp = sliders[j].getLabel();
//            if (temp == "Text Position: ") {
//                for(int i = 0; i < sliders.size(); i++){
//                    if(sliders[i].getLabel() == "Text Position: ") {
//                        sliders[i].addEventHandler(window, event);
//                    }
//                }
//            }
//
//            if (temp == "Shadow Pos: ") {
//                for(int i = 0; i < sliders.size(); i++){
//                    if(sliders[i].getLabel() == "Shadow Pos: ") {
//                        sliders[i].addEventHandler(window, event);
//                    }
//                }
//            }

    if(MouseEvents<Slider>::draggedOver(shadowPos, window, event)){
        shadowPos.addEventHandler(window, event);
        skew.disable();
        textOpac.disable();
        textSize.disable();
        skew.disable();
        backOpac.disable();
        textY.disable();
        shadowY.disable();
    }

    if(MouseEvents<Slider>::draggedOver(textOpac, window, event)) {
        textOpac.addEventHandler(window, event);
        textSize.disable();
        skew.disable();
        backOpac.disable();
        textY.disable();
        shadowY.disable();
        skew.disable();
        shadowPos.disable();
    }

    if(MouseEvents<Slider>::draggedOver(textSize, window, event)){
        textSize.addEventHandler(window, event);
        skew.disable();
        backOpac.disable();
        textY.disable();
        shadowY.disable();
        skew.disable();
        shadowPos.disable();
        textOpac.disable();
    }

    if(MouseEvents<Slider>::draggedOver(skew, window, event)){
        //skew.enable();
        textSize.disable();
        backOpac.disable();
        textY.disable();
        shadowY.disable();
        skew.disable();
        shadowPos.disable();
        textOpac.disable();
        skew.addEventHandler(window, event);
    }

    if(MouseEvents<Slider>::draggedOver(backOpac, window, event)){
        backOpac.addEventHandler(window, event);
        textY.disable();
        shadowY.disable();
        skew.disable();
        shadowPos.disable();
        textOpac.disable();
        textSize.disable();
        skew.disable();
    }

    if(MouseEvents<Slider>::draggedOver(textY, window, event)){
        textY.addEventHandler(window, event);
        shadowY.disable();
        skew.disable();
        shadowPos.disable();
        textOpac.disable();
        textSize.disable();
        skew.disable();
        backOpac.disable();
    }

    if(MouseEvents<Slider>::draggedOver(shadowY, window, event)){
        shadowY.addEventHandler(window, event);
        skew.disable();
        shadowPos.disable();
        textOpac.disable();
        textSize.disable();
        skew.disable();
        backOpac.disable();
        textY.disable();
    }

    for(int i = 0; i < sliders.size(); i++){
        sliders[i].addEventHandler(window, event);
    }
    if(checkState(OPENPROJECT)){
        disableState(OPENPROJECT);
    }
    if(checkState(NEWPROJECT)){
        projClose = false;
        enableState(RESET);
        input.clear();
        input.setPosition({20, 450});
//        picker.setColor(sf::Color::Black);
//        textcolor.setColor(sf::Color::White);
        disableState(NEWPROJECT);
    }
    if(checkState(CLOSEPROJECT)){
        projClose = true;
        newProj = false;
        disableState(CLOSEPROJECT);
    }
    if(checkState(QUIT)){
        window.close();
    }
    if(checkState(EXPORT)){
//        filenameWindow.run();
//        string filename = filenameWindow.getLabel();
//        filename = "Logos/" + filename + ".png";
//
//        texture.create((int)background.getSize().x, window.getSize().y);
//        texture.update(window);
//        source = texture.copyToImage();
//
//        image.create(background.getGlobalBounds().width, background.getGlobalBounds().height, sf::Color::Transparent);
//        image.copy(source, 10, 10,sf::IntRect((int)background.getPosition().x,(int)background.getPosition().y + menuBar.getGlobalBounds().height, (int)background.getGlobalBounds().width, (int)background.getGlobalBounds().height - menuBar.getGlobalBounds().height));
//
//        image.saveToFile(filename);
//        States::enableState(EXPORT);
//        window.close();
    }
}



void LogoMaker::update() {
    input.update();
    sf::Color color = picker.getColor();
    background.setFillColor(color);
    if(checkState(RESET)){
        picker.setColor(sf::Color::Black);
        textcolor.setColor(sf::Color::White);
        disableState(RESET);

    }
    bigText.setString(input.getString());
    bigText.setFillColor(textcolor.getColor());
    shadow.setString(input.getString());
    shadow.setFillColor(textcolor.getColor());
    dropdown.update();
    string temp = dropdown.getLabel();
    if(temp == "Arial"){
        bigText.setFont(Fonts::getFont(Arial));
        shadow.setFont(Fonts::getFont(Arial));
    }
    if (temp == "OpenSansBold"){
        bigText.setFont(Fonts::getFont(OPENSANSBOLD));
        shadow.setFont(Fonts::getFont(OPENSANSBOLD));
    }
    if(temp == "Arcade"){
        bigText.setFont(Fonts::getFont(ARCADE));
        shadow.setFont(Fonts::getFont(ARCADE));
    }
    if(temp == "Waltograph"){
        bigText.setFont(Fonts::getFont(WALTOGRAPH));
        shadow.setFont(Fonts::getFont(WALTOGRAPH));
    }
    for (auto &iter: sliders) {
        iter.update();
    }
    shadow.setPosition(shadowPos.getSliderVal() ,shadow.getPosition().y);
//    bigText.setPosition(textPos.getSliderVal(), textY.getSliderVal());

//    textPos.update();
//    shadowPos.update();
//    textOpac.update();
//    textSize.update();
//    skew.update();
//    backOpac.update();
//    textY.update();
//    shadowY.update();
}

void LogoMaker::setPosition(float x, float y){
    input.setPosition({x, y});
    sliders.at(0).setPosition(x + input.getPosition().x, input.getGlobalBounds().top + input.getGlobalBounds().height + yPadding); //text opacity pos

    sliders.at(1).setPosition(sliders.at(0).getPosition().x,sliders.at(0).getPosition().y + sliders.at(0).getGlobalBounds().height + yPadding);//background opacity pos

    sliders.at(2).setPosition(x + sliders.at(0).getPosition().x + sliders.at(0).getGlobalBounds().width + xPadding,sliders.at(0).getPosition().y);//font size pos

    sliders.at(3).setPosition(x + xPadding + sliders.at(2).getPosition().x + sliders.at(2).getGlobalBounds().width,sliders.at(0).getPosition().y);//skew pos

    sliders.at(4).setPosition(sliders.at(0).getPosition().x,sliders.at(1).getPosition().y + sliders.at(1).getGlobalBounds().height + yPadding);//text x-axis pos

    sliders.at(5).setPosition(sliders.at(0).getPosition().x,sliders.at(4).getPosition().y + sliders.at(4).getGlobalBounds().height + yPadding);//text y-axis pos

    sliders.at(6).setPosition(sliders.at(0).getPosition().x,sliders.at(5).getPosition().y + sliders.at(5).getGlobalBounds().height + yPadding);//shadow x-axis pos

    sliders.at(7).setPosition(sliders.at(0).getPosition().x,sliders.at(6).getPosition().y + sliders.at(6).getGlobalBounds().height + yPadding);//shadow y-axis pos


}