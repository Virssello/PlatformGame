//
// Created by 48510 on 12.11.2021.
//

#include <iostream>
#include "Menu.h"
#include "GameScreen.h"

Menu::Menu(GameDataRef data) : _data(data)
{

}

void Menu::Init()
{
    texMenu.loadFromFile("Menu.png");
    menu.setTexture(texMenu);
}

void Menu::HandleInput()
{
    sf::Event event;
    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(this->_data->window).x > 490 && sf::Mouse::getPosition(this->_data->window).x < 808 && sf::Mouse::getPosition(this->_data->window).y > 390 && sf::Mouse::getPosition(this->_data->window).y < 500)
        {
            this->_data->wrapper.AddState(StateRef(new GameScreen(_data)));
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(this->_data->window).x > 490 && sf::Mouse::getPosition(this->_data->window).x < 808 && sf::Mouse::getPosition(this->_data->window).y > 540 && sf::Mouse::getPosition(this->_data->window).y < 650)
        {
            this->_data->window.close();
        }
    }
}

void Menu::Update() {
}
void Menu::Draw()
{
    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw(menu);
    this->_data->window.display();
}
