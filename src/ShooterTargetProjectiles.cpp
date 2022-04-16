
#include "include/ShooterTargetProjectiles.hpp"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include <cstdlib>

ShooterTargetProjectiles::ShooterTargetProjectiles():mWindow(sf::VideoMode(640,450),"Shoot Target Projectiles with mouse",sf::Style::Default){
    srand(time(NULL));

    mWindow.setFramerateLimit(60);
    projectile.setRadius(5.f);
    projectile.setFillColor(sf::Color::Red);
    projectiles.push_back(projectile);

    //enemy
    enemy.setFillColor(sf::Color::Magenta);
    enemy.setSize(sf::Vector2f(50.f,50.f));
    enemies.push_back(enemy);

    player.setFillColor(sf::Color::White);
    player.setRadius(30.f);
    player.setPointCount(3);
    player.setPosition(mWindow.getSize().x/2 - player.getRadius(),mWindow.getSize().y - player.getRadius()*2+10.f);
}

void ShooterTargetProjectiles::run(){

    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void ShooterTargetProjectiles::processEvents(){

    sf::Event event;

    while (mWindow.pollEvent(event)) {
        
        switch (event.type) {

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
    

}

void ShooterTargetProjectiles::update(){
    playerCenter = sf::Vector2f(player.getPosition().x+player.getRadius()-4.f,player.getPosition().y+player.getRadius());

    if(shootTimer < 5)
        shootTimer++;

    player.setPosition(sf::Mouse::getPosition(mWindow).x,player.getPosition().y);

    // Projectiles
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && shootTimer >= 3 ){ // Shoot
        projectile.setPosition(playerCenter);
        projectiles.push_back(sf::CircleShape(projectile));
        shootTimer = 0;
    }

    for (size_t i=0;i<projectiles.size();i++) {
        projectiles[i].move(0.f,-10.f);
        
        if(projectiles[i].getPosition().y <= 10){
            projectiles.erase(projectiles.begin()+i);
        }
    }

    //Enemies
    if(enemiesSpawnTime < 20)
        enemiesSpawnTime++;

    if (enemiesSpawnTime >=20) {
        enemy.setPosition(rand()% int((mWindow.getSize().x-enemy.getSize().x)),0.f);
        enemies.push_back(sf::RectangleShape(enemy));
        enemiesSpawnTime =0;
    }

    for (size_t i=0;i<enemies.size();i++) {
        enemies[i].move(0.f,5.f);

        if (enemies[i].getPosition().y > mWindow.getSize().y) {
            enemies.erase(enemies.begin()+i);
        }
    }

    // Collisions
    for (size_t i=0; i<projectiles.size();i++) {
        
        for (size_t k=0;k < enemies.size(); k++) {
            if (projectiles[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds())) {
                projectiles.erase(projectiles.begin()+i);
                enemies.erase(enemies.begin()+k);
                break;
            }
        }
    }
}

void ShooterTargetProjectiles::render(){
    mWindow.clear();
    mWindow.draw(player);

    // mWindow.draw(projectile);
    for (auto ene:enemies) {
        mWindow.draw(ene);
    }

    for (auto proj:projectiles) {
        mWindow.draw(proj);
    }

    mWindow.display();
}



ShooterTargetProjectiles::~ShooterTargetProjectiles(){
    
}