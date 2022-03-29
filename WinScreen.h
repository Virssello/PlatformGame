//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_WINSCREEN_H
#define MAIN_CPP_WINSCREEN_H


#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.h"
#include "Game.h"
///klasa odpowiedzialna za wyświetlanie ekranu gry w momencie wygranej
class WinScreen : public State{
public:
    ///funkcja rysująca ekran po wygraniu rozgrywki
    WinScreen(GameDataRef data,float czas);
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
    sf::Sprite winState;
    sf::Texture texWin;
    sf::View endCam;
    //global data accessor
    GameDataRef _data;
    float _czas;
};


#endif //MAIN_CPP_WINSCREEN_H
