//
// Created by 48510 on 12.11.2021.
//

#include "Game.h"
#include "Menu.h"
#include "GameScreen.h"

Game::Game(int width, int height, std::string title)
{
    _data->window.create(sf::VideoMode(width, height), title, sf::Style::Close);
    _data->wrapper.AddState(StateRef(new Menu(this->_data)));
    this->Run();
}

void Game::Run()
{
    while (this->_data->window.isOpen())
    {
        this->_data->wrapper.ProcessStateChanges();
        this->_data->wrapper.GetActiveState()->HandleInput();
        this->_data->wrapper.GetActiveState()->Update();
        this->_data->wrapper.GetActiveState()->Draw();
    }
}


