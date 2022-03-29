//
// Created by 48510 on 12.11.2021.
//

#ifndef MAIN_CPP_MAPOBJECT_H
#define MAIN_CPP_MAPOBJECT_H


#include <vector>
#include <SFML/Graphics.hpp>
///klasa odpowiedzialna za umieszczanie obiektów na planszy
class MapObject {
public:
    ///funkcja odpowiedzialna rysująca platformy na planszy
    void platformy(std::vector<sf::Sprite>& platforms,float x,float y,float s_x1, float s_y2);
    ///funkcja odpowiedzialna rysująca monety na planszy
    void monety(std::vector<sf::Sprite>& coins,float x,float y);
    ///funkcja odpowiedzialna rysująca przciwników na planysz
    void przeciwnik(std::vector<sf::Sprite>& enemies,float x,float y);
    ///funkcja odpowiedzialna za rysowanie pociskow
    void pocisk(std::vector<sf::Sprite>& projectile,float x,float y);
    ///funkcja odpowiedzialna rysująca kolce na planszy
    void kolce(std::vector<sf::Sprite>& spikes,float x,float y,float s_x1, float s_y2);
};


#endif //MAIN_CPP_MAPOBJECT_H
