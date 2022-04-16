#pragma once
#include <iostream>
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <vector>

class ShooterTargetProjectiles{

    private:
        sf::Vector2f playerCenter;
        sf::CircleShape projectile;
        sf::CircleShape player;
        sf::RectangleShape enemy;
        std::vector<sf::RectangleShape> enemies;
        std::vector<sf::CircleShape> projectiles;
        int shootTimer=0;
        int enemiesSpawnTime = 0;


    private:
        sf::RenderWindow mWindow;

    public:
        ShooterTargetProjectiles();
        ~ShooterTargetProjectiles();
        void run();

    private:
        void processEvents();
        void update();
        void render();
        void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);
};