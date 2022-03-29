//
// Created by 48510 on 12.11.2021.
//

#include <iostream>
#include "MapObject.h"

void MapObject::platformy(std::vector<sf::Sprite>& platforms,float x,float y,float s_x1, float s_y2)
{
    sf::Sprite p1;
    p1.setPosition(x,y);
    p1.setScale(s_x1,s_y2);
    platforms.push_back(p1);
}

void MapObject::monety(std::vector<sf::Sprite>& coins,float x,float y)
{
    sf::Sprite p1;
    p1.setPosition(x,y);
    coins.push_back(p1);
}

void MapObject::pocisk(std::vector<sf::Sprite>& projectile,float x,float y)
{
    sf::Sprite p1;
    p1.setPosition(x,y);
    projectile.push_back(p1);
}

void MapObject::przeciwnik(std::vector<sf::Sprite>& enemies,float x,float y)
{
    sf::Sprite p1;
    p1.setPosition(x,y);
    enemies.push_back(p1);
}

void MapObject::kolce(std::vector<sf::Sprite>& spikes,float x,float y,float s_x1, float s_y2)
{
    sf::Sprite k1;
    k1.setPosition(x,y);
    k1.setScale(s_x1,s_y2);
    spikes.push_back(k1);
}