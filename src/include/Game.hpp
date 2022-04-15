#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/Window/Keyboard.hpp"

class Game{
    public:
        Game();
        ~Game();
        void run();
    private:
        
        void processEvents();
        void update(sf::Time deltaTime);
        void render();
        void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);

    private:
        bool mIsMovingUp,mIsMovingDown,mIsMovingLeft,mIsMovingRight;
        sf::RenderWindow mWindow;
        sf::CircleShape mPlayer;

};