#include "GameScreen.h"
#include "WinScreen.h"
#include "LoseScreen.h"
#include <iostream>

GameScreen::GameScreen(GameDataRef data) : _data(data)
{
}

void GameScreen::Init() {
    this->_data->window.setFramerateLimit(120);
    koniec.setSize({20, 20});
    koniec.setPosition(4130, 130);
    finish.loadFromFile("finish.png");
    koniec.setTexture(&finish);
    player.setPosition(50, 816);
    texture.loadFromFile("adventurer-Sheet.png");
    player.setTexture(texture);
    player.setTextureRect(rectSourceSprite);
    tlo.setSize({1280, 960});
    texture1.loadFromFile("Tlo.jpg");
    tlo.setTexture(&texture1);
    texPlatform.loadFromFile("Platforma.png");
    texCoin.loadFromFile("coin.png");
    objects.platformy(platforms, 150, 700, 1, 1);
    objects.platformy(platforms, 350, 570, 1, 1);
    objects.platformy(platforms, 540, 450, 1, 1);
    objects.platformy(platforms, 750, 350, 4, 1);
    objects.platformy(platforms, 2200, 750, 1, 1);
    objects.platformy(platforms, 2320, 680, 1, 1);
    objects.platformy(platforms, 2200, 600, 1, 1);
    objects.platformy(platforms, 2320, 520, 1, 1);
    objects.platformy(platforms, 2200, 420, 1, 1);
    objects.platformy(platforms, 2320, 340, 1, 1);
    objects.platformy(platforms, 2470, 280, 5, 1);
    objects.platformy(platforms, 3700, 750, 1, 1);
    objects.platformy(platforms, 3900, 650, 1, 1);
    objects.platformy(platforms, 3700, 550, 1, 1);
    objects.platformy(platforms, 3900, 450, 1, 1);
    objects.platformy(platforms, 3700, 350, 1, 1);
    objects.platformy(platforms, 3900, 250, 1, 1);
    objects.platformy(platforms, 4100, 150, 1, 1);
    objects.monety(coins, 700, 260);
    objects.monety(coins, 480, 400);
    objects.monety(coins, 1100, 300);
    objects.monety(coins, 1100, 370);
    objects.monety(coins, 1100, 440);
    objects.monety(coins, 1100, 510);
    objects.monety(coins, 1100, 580);
    objects.monety(coins, 1100, 650);
    objects.monety(coins, 1100, 720);
    objects.monety(coins, 3800, 600);
    objects.monety(coins, 3850, 500);
    objects.monety(coins, 3800, 400);
    objects.monety(coins, 3850, 300);
    texEnemies.loadFromFile("Bacteria.png");
    objects.przeciwnik(enemies, 790, 300);
    objects.przeciwnik(enemies, 1200, 765);
    texSpikes.loadFromFile("spikes.png");
    objects.kolce(spikes, 200, 800, 1, 1);
    objects.kolce(spikes, 403, 800, 1, 1);
    objects.kolce(spikes, 606, 800, 1, 1);
    objects.kolce(spikes, 809, 800, 1, 1);
    objects.kolce(spikes, 2470, 800, 1, 1);
    objects.kolce(spikes, 2673, 800, 1, 1);
    objects.kolce(spikes, 2950, 800, 0.9, 1);
    objects.kolce(spikes, 3260, 800, 0.9, 1);
    objects.kolce(spikes, 3950, 800, 1, 1);
    czas.setPosition(200, 400);
    if (!font.loadFromFile("Testowa_czcionka.ttf")) {
        std::cout << "Blad z ladowanie";
        system("pause");
    }
    tekst.setFont(font);
    tekst.setCharacterSize(25);
    tekst.setFillColor(sf::Color::Red);
    tekst2.setFont(font);
    tekst2.setCharacterSize(25);
    tekst2.setFillColor(sf::Color::Red);
    m_PlayerCamera.setCenter((float) this->_data->window.getSize().x / 2,
                             ((float) this->_data->window.getSize().y / 2));
    m_PlayerCamera.setSize(this->_data->window.getSize().x, this->_data->window.getSize().y);
    punkty = 0;
    texPocisk.loadFromFile("pocisk.png");
    shoot=true;
}

void GameScreen::HandleInput()
{
    sf::Event event;
    if(shoot==true) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if(m_MoveState==MOVE_LEFT) {
                objects.pocisk(projetilesL, player.getGlobalBounds().left + player.getGlobalBounds().width / 2,
                               player.getGlobalBounds().top + player.getGlobalBounds().height / 2);
            }
            else{
                objects.pocisk(projetilesR, player.getGlobalBounds().left + player.getGlobalBounds().width / 2,
                               player.getGlobalBounds().top + player.getGlobalBounds().height / 2);
            }
            shoot=false;
        }
    }
    if(isJumping==true){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rectSourceSprite.top = 300;
            velocity.y = -8.5;
            isJumping = false;
        } else rectSourceSprite.top = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        rectSourceSprite.top = 30;
        velocity.x = 3;
        if(m_MoveState==MOVE_LEFT){
            rectSourceSprite.width = abs(rectSourceSprite.width);
        }
        m_MoveState = MOVE_RIGHT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rectSourceSprite.top = 30;
        velocity.x = -3;
        if(m_MoveState==MOVE_RIGHT){
            rectSourceSprite.width = -abs(rectSourceSprite.width);
        }
        m_MoveState = MOVE_LEFT;
    } else rectSourceSprite.top = 0;
    while (this->_data->window.pollEvent(event)) {
        switch (event.type) {

            case sf::Event::Closed:
                this->_data->window.close();
        }
    }

}

void GameScreen::Update() {
    for (int i = 0; i < projetilesR.size(); i++) {
        projetilesR[i].move(4, 0);
        if(projetilesR[i].getPosition().x>player.getPosition().x+1280)
        {
            projetilesR.erase(projetilesR.begin()+i);
        }
    }
    for (int i = 0; i < projetilesL.size(); i++) {
        projetilesL[i].move(-4, 0);
        if(projetilesL[i].getPosition().x<player.getPosition().x-1280)
        {
            projetilesL.erase(projetilesL.begin()+i);
        }
    }
    sf::Time elapsed = clock.getElapsedTime();
    float x = elapsed.asSeconds();
    tekst.setPosition(m_PlayerCamera.getCenter().x,0);
    tekst.setString(std::to_string(x));
    tekst2.setPosition(m_PlayerCamera.getCenter().x-500,0);
    std::string liczbaPunktow = std::to_string(punkty);
    tekst2.setString("Punkty: " + liczbaPunktow);
    int test=x;
    sf::Time shotTimer = clock2.getElapsedTime();
    if(shotTimer.asSeconds()>2)
    {
        shoot=true;
        clock2.restart();
    }
    for(int i=0;i<enemies.size();i++)
    {
        if((test/1)%2==0)
        {
            enemies[i].move(1.5,0);
        }
        else
        {
            enemies[i].move(-1.5,0);
        }
    }
    for(int i=0;i<coins.size();i++){
        if(player.getGlobalBounds().intersects(coins[i].getGlobalBounds()))
        {
            coins.erase(coins.begin()+i);
            punkty+=100;
        }
    }
    for(int i=0;i<projetilesR.size();i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (projetilesR[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                projetilesR.erase(projetilesR.begin() + i);
                enemies.erase(enemies.begin() + j);
                punkty+=200;
            }
        }
    }
    for(int i=0;i<projetilesL.size();i++) {
        for (int j = 0; j < enemies.size(); j++) {
            if (projetilesL[i].getGlobalBounds().intersects(enemies[j].getGlobalBounds())) {
                projetilesL.erase(projetilesL.begin() + i);
                enemies.erase(enemies.begin() + j);
                punkty+=200;
            }
        }
    }
    if(isJumping == false){
        rectSourceSprite.top = 300;
        if(rectSourceSprite.left == 20){
            rectSourceSprite.left = 0;
        }
    }
    if(playerClock.getElapsedTime().asSeconds() > 0.1f){
        if(rectSourceSprite.left == 60){
            rectSourceSprite.left = 0;
        }else{
            rectSourceSprite.left += 20;
        }
        player.setTextureRect(rectSourceSprite);
        playerClock.restart();
    }
    if (m_MoveState == MOVE_LEFT) {
        if (m_PlayerCamera.getCenter().x - (this->_data->window.getSize().x / 2) >= 0) {
            if (player.getPosition().x +350<= (tlo.getGlobalBounds().width * 50 - this->_data->window.getSize().x / 2)) {
                if (player.getPosition().x > 3300) {
                } else {
                    m_PlayerCamera.move(velocity.x, 0);
                    tlo.move(velocity.x, 0);
                    this->_data->window.setView(m_PlayerCamera);
                }
            }
        }
    }
    if (m_MoveState == MOVE_RIGHT) {
        if ((player.getPosition().x) +350 >= m_PlayerCamera.getCenter().x) {
            if (player.getPosition().x +350 <= (tlo.getGlobalBounds().width * 50 - this->_data->window.getSize().x / 2)) {
                if (player.getPosition().x > 3300) {
                } else {
                    m_PlayerCamera.move(velocity.x, 0);
                    tlo.move(velocity.x, 0);
                    this->_data->window.setView(m_PlayerCamera);
                }
            }
        }
    }
    player.move(velocity);
    velocity.x=0.f;
    velocity.y+=0.2;
    if(player.getPosition().y<0)
    {
        player.setPosition(player.getPosition().x,0);
    }
    if(player.getPosition().x<0)
        player.setPosition(0,player.getPosition().y);
    if(player.getPosition().x +player.getGlobalBounds().width>4240)
    {
        player.setPosition(4240-player.getGlobalBounds().width,player.getPosition().y);
    }
    if(player.getPosition().y +player.getGlobalBounds().height>816)
    {
        isJumping=true;
        player.setPosition(player.getPosition().x,816-player.getGlobalBounds().height);
    }
    for(int i=0;i<platforms.size();i++)
    {
        sf::FloatRect gracz = player.getGlobalBounds();
        sf::FloatRect wallbounds;
        wallbounds=platforms[i].getGlobalBounds();
        if(wallbounds.intersects(gracz))
        {
            //Right Player Collision
            if (gracz.left < wallbounds.left && gracz.left + gracz.width < wallbounds.left + wallbounds.width
                && gracz.top<wallbounds.top + wallbounds.height
                && gracz.top + gracz.height>wallbounds.top
                    )
            {
                velocity.x = 0.0;
                player.setPosition(wallbounds.left - gracz.width, gracz.top);
            }
                //Left Player Collision
            else if (gracz.left > wallbounds.left &&
                     gracz.left + gracz.width > wallbounds.left + wallbounds.width
                     && gracz.top<wallbounds.top + wallbounds.height
                     && gracz.top + gracz.height>wallbounds.top

                    )
            {
                velocity.x = 0.0;
                player.setPosition(wallbounds.left + wallbounds.width, gracz.top);
            }
                //Top Player Collision
            else if (gracz.top > wallbounds.top &&
                     gracz.top + gracz.height > wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                velocity.y = 0.0;
                player.setPosition(gracz.left, wallbounds.top + wallbounds.height);
            }
                //Bottom Player Collision
            else if (gracz.top < wallbounds.top &&
                     gracz.top + gracz.height < wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                isJumping=true;
                velocity.y = 0.0;
                player.setPosition(gracz.left, wallbounds.top - gracz.height);
            }
        }
    }
    for(int i=0;i<spikes.size();i++)
    {
        sf::FloatRect gracz = player.getGlobalBounds();
        sf::FloatRect wallbounds;
        wallbounds=spikes[i].getGlobalBounds();
        if(wallbounds.intersects(gracz))
        {
            //Right Player Collision
            if (gracz.left < wallbounds.left && gracz.left + gracz.width < wallbounds.left + wallbounds.width
                && gracz.top<wallbounds.top + wallbounds.height
                && gracz.top + gracz.height>wallbounds.top
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Left Player Collision
            else if (gracz.left > wallbounds.left &&
                     gracz.left + gracz.width > wallbounds.left + wallbounds.width
                     && gracz.top<wallbounds.top + wallbounds.height
                     && gracz.top + gracz.height>wallbounds.top
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Top Player Collision
            else if (gracz.top > wallbounds.top &&
                     gracz.top + gracz.height > wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Bottom Player Collision
            else if (gracz.top < wallbounds.top &&
                     gracz.top + gracz.height < wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
        }
    }
    for(int i=0;i<enemies.size();i++)
    {
        sf::FloatRect gracz = player.getGlobalBounds();
        sf::FloatRect wallbounds;
        wallbounds=enemies[i].getGlobalBounds();
        if(wallbounds.intersects(gracz))
        {
            //Right Player Collision
            if (gracz.left < wallbounds.left && gracz.left + gracz.width < wallbounds.left + wallbounds.width
                && gracz.top<wallbounds.top + wallbounds.height
                && gracz.top + gracz.height>wallbounds.top
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Left Player Collision
            else if (gracz.left > wallbounds.left &&
                     gracz.left + gracz.width > wallbounds.left + wallbounds.width
                     && gracz.top<wallbounds.top + wallbounds.height
                     && gracz.top + gracz.height>wallbounds.top
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Top Player Collision
            else if (gracz.top > wallbounds.top &&
                     gracz.top + gracz.height > wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
                //Bottom Player Collision
            else if (gracz.top < wallbounds.top &&
                     gracz.top + gracz.height < wallbounds.top + wallbounds.height
                     && gracz.left<wallbounds.left + wallbounds.width
                     && gracz.left + gracz.width>wallbounds.left
                    )
            {
                this->_data->wrapper.AddState(StateRef(new LoseScreen(_data,x)));
            }
        }
    }
    sf::FloatRect gracz = player.getGlobalBounds();
    sf::FloatRect end =  koniec.getGlobalBounds();
    if(gracz.intersects(end))
    {
        writeFile.open("Ranking.txt",std::ios::app);
        if(writeFile.is_open())
        {
            writeFile.seekp(std::ios::end);
            writeFile << x <<'\n';
        }
        writeFile.close();
        this->_data->wrapper.AddState(StateRef(new WinScreen(_data,x)));
    }
}

void GameScreen::Draw()
{
    this->_data->window.clear(sf::Color::Black);
    this->_data->window.draw(tlo);
    this->_data->window.draw(koniec);
    for(int i=0;i<platforms.size();i++)
    {
        platforms[i].setTexture(texPlatform);
        this->_data->window.draw(platforms[i]);
    }
    for(int i=0;i<coins.size();i++)
    {
        coins[i].setTexture(texCoin);
        this->_data->window.draw(coins[i]);
    }
    for(int i=0;i<spikes.size();i++) {
        spikes[i].setTexture(texSpikes);
        this->_data->window.draw(spikes[i]);
    }
    for(int i=0;i<enemies.size();i++) {
        enemies[i].setTexture(texEnemies);
        this->_data->window.draw(enemies[i]);
    }
    for(int i=0;i<projetilesR.size();i++){
        projetilesR[i].setTexture(texPocisk);
        this->_data->window.draw(projetilesR[i]);
    }
    for(int i=0;i<projetilesL.size();i++){
        projetilesL[i].setTexture(texPocisk);
        this->_data->window.draw(projetilesL[i]);
    }
    this->_data->window.draw(player);
    this->_data->window.draw(tekst);
    this->_data->window.draw(tekst2);
    this->_data->window.display();
}

