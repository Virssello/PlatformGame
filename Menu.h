//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H
#include "State.h"
#include "Game.h"
///klasa odpowiedzialna za wyświetlenie okna menu
class Menu : public State {
public:
    ///funkcja rysująca menu
    Menu(GameDataRef data);
    ///funkcja rysująca elementy w oknie gry
    void Draw();
    ///funkcja odpowiedzialna za bieżacy stan ekranu
    void Update();
    ///funkcja obsługująca urządzenia końcowe
    void HandleInput();
    ///funkcja odpowiedzialna za konstruktory
    void Init();
private:
    sf::Sprite menu;
    sf::Texture texMenu;
    GameDataRef _data;
};


#endif //MAIN_CPP_MENU_H
