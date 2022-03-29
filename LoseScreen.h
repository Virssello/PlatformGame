//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_LOSESCREEN_H
#define MAIN_CPP_LOSESCREEN_H


#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include "State.h"
#include "Game.h"
///klasa odpowiedzialna za wyświetlenie ekranu w momencie przegranej
class LoseScreen : public State{
public:
    ///funkcja wyświetlająca ekran porażki
    LoseScreen(GameDataRef datam,float czas);
    ///funkcja rysująca elementy w oknie gry
    void Draw();
    ///funkcja odpowiedzialna za bieżacy stan ekranu
    void Update();
    ///funkcja obsługująca urządzenia końcowe
    void HandleInput();
    ///funkcja odpowiedzialna za konstruktory
    void Init();
private:
    std::string tmp;
    std::vector<float> score;
    std:: ifstream readFile;
    sf::Text tekst;
    sf::Text tekst2;
    sf::Font font;
    sf::Sprite loseState;
    sf::Texture texLose;
    sf::View endCam;
    //global data accessor
    GameDataRef _data;
    float _czas;
};

#endif //MAIN_CPP_LOSESCREEN_H
