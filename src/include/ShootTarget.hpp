#pragma once

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Keyboard.hpp"
class ShootTarget{

    private:
        sf::CircleShape hoop;
        sf::CircleShape ball;
        int direction = 0;
        bool isShoot = false;
        int score=0;

    private:
        sf::RenderWindow mWindow;

    public:
        ShootTarget();
        ~ShootTarget();
        void run();

    private:
        void processEvents();
        void update();
        void render();
        void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);
};