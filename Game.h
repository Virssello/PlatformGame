//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include <SFML/Graphics.hpp>
#include "StateWrapper.h"
#include <memory>
#include <string>
struct GameData
{
    StateWrapper wrapper;
    sf::RenderWindow window;
};

typedef std::shared_ptr<GameData> GameDataRef;
///klasa odpowiedzialna za tworzenie okna gry
class Game {
public:
    Game(int width, int height,std::string title);
private:
    GameDataRef _data = std::make_shared<GameData>();
    void Run();
};


#endif //MAIN_CPP_GAME_H
