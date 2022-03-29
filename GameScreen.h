//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_GAMESCREEN_H
#define MAIN_CPP_GAMESCREEN_H

#include <fstream>
#include "State.h"
#include "Game.h"
#include "MapObject.h"
///klasa odpowiedzialna za główny ekran rozgrywki
class GameScreen : public State {
public:
    ///funkcja odpowiedzialna za obsługę ekranu
    GameScreen(GameDataRef data);
    ///funkcja rysująca elementy w oknie gry
    void Draw();
    ///funkcja odpowiedzialna za bieżacy stan ekranu
    void Update();
    ///funkcja obsługująca urządzenia końcowe
    void HandleInput();
    ///funkcja odpowiedzialna za konstruktory
    void Init();
private:
    std::vector<sf::Sprite> projetilesR;
    std::vector<sf::Sprite> projetilesL;
    sf::Texture texPocisk;
    std::ofstream writeFile;

    int punkty;
    enum InputStates {
        MOVE_RIGHT = 3,
        MOVE_LEFT = 4,
    };
    int m_MoveState;
    sf::RectangleShape koniec;
    sf::Vector2f velocity{0,0};
    sf::Clock playerClock;
    sf::Texture texture;
    sf::Sprite player;
    sf::Texture finish;
    sf::IntRect rectSourceSprite{0, 0, 20, 30};
    sf::RectangleShape tlo;
    sf::Texture texture1;
    sf::Texture texPlatform;
    sf::Texture texCoin;
    sf::Texture texEnemies;
    std::vector<sf::Sprite> platforms;
    std::vector<sf::Sprite> coins;
    std::vector<sf::Sprite> enemies;
    MapObject objects;
    sf::Texture texSpikes;
    std::vector<sf::Sprite> spikes;
    sf::Clock clock;
    sf::Clock clock2;
    bool isJumping=true;
    bool shoot=true;
    sf::Text czas;
    sf::Font font;
    sf::Text tekst;
    sf::Text tekst2;
    sf::View m_PlayerCamera;
    GameDataRef _data;
};


#endif //MAIN_CPP_GAMESCREEN_H
