//
// Created by 48510 on 12.11.2021.
//

#include <iostream>
#include "WinScreen.h"
#include "GameScreen.h"

WinScreen::WinScreen(GameDataRef data,float czas) : _data(data),_czas(czas)
{
}

void WinScreen::Init()
{
    endCam.setCenter((float)this->_data->window.getSize().x/2,((float)this->_data->window.getSize().y/2));
    endCam.setSize(this->_data->window.getSize().x,this->_data->window.getSize().y);
    texWin.loadFromFile("Win.png");
    winState.setTexture(texWin);
    this->_data->window.setView(endCam);
    if(!font.loadFromFile("Testowa_czcionka.ttf")){
        std::cout<<"Blad z ladowanie";
        system("pause");
    }
    tekst2.setFont(font);
    tekst2.setCharacterSize(25);
    tekst2.setFillColor(sf::Color::Red);
    tekst2.setString("Twoj czas to: "+std::to_string(_czas));
    tekst2.setPosition(490,380);
    tekst.setFont(font);
    tekst.setCharacterSize(25);
    tekst.setFillColor(sf::Color::Red);
    readFile.open("Ranking.txt");
    if (readFile.is_open())
    {
        try
        {
            while(!readFile.eof())
            {
                getline (readFile, tmp);
                score.push_back(std::stof(tmp));
            }
        }
        catch(std::invalid_argument e)
        {
            std::cout<<e.what();
        }
    }
    readFile.close();
    std::sort(score.begin(),score.end(),std::less<float>());
    if(score.size()>5)
        score.resize(5);
    for(int i=0; i<score.size(); i++)
    {
        tmp.append(std::to_string(score[i]));
        tmp.append("\n");
    }
    tekst.setString(tmp);
    tekst.setPosition(580,550);
}

void WinScreen::HandleInput()
{
    sf::Event event;
    while (this->_data->window.pollEvent(event))
    {
        if (sf::Event::Closed == event.type)
        {
            this->_data->window.close();
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(this->_data->window).x > 343 && sf::Mouse::getPosition(this->_data->window).x < 592 && sf::Mouse::getPosition(this->_data->window).y > 830 && sf::Mouse::getPosition(this->_data->window).y < 900)
        {
            this->_data->wrapper.AddState(StateRef(new GameScreen(_data)));
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && sf::Mouse::getPosition(this->_data->window).x > 666 && sf::Mouse::getPosition(this->_data->window).x < 917 && sf::Mouse::getPosition(this->_data->window).y > 830 && sf::Mouse::getPosition(this->_data->window).y < 900)
        {
            this->_data->window.close();
        }
    }
}

void WinScreen::Update() {
}
void WinScreen::Draw()
{
    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw(winState);
    this->_data->window.draw(tekst);
    this->_data->window.draw(tekst2);
    this->_data->window.display();
}
