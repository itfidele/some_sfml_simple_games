#include "include/Game.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>


Game::Game():mWindow(sf::VideoMode(640,480),"SFML Application",sf::Style::Default),mPlayer(){
    mWindow.setFramerateLimit(60);
    
    mPlayer.setRadius(50.f);
    mPlayer.setPosition(100.f,100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}


void Game::run(){
    sf::Clock clock;
    
    while (mWindow.isOpen()) {

        sf::Time deltaTime=clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}



void Game::processEvents(){
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        
        switch(event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code,true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code,false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::Resized:
                break;
            default:
                break;
                
        }
    }
}

void Game::handlePlayerInput(sf::Keyboard::Key key,bool isPressed){


    if(key == sf::Keyboard::Key::W ){
        mIsMovingUp = isPressed;
        mPlayer.setFillColor(sf::Color::Blue);
    }
    else if(key == sf::Keyboard::Key::S){
        mIsMovingDown = isPressed;
        mPlayer.setFillColor(sf::Color::Red);
    }
    else if(key == sf::Keyboard::Key::A){
        mIsMovingLeft = isPressed;
        mPlayer.setFillColor(sf::Color::Magenta);
    }
    else if(key == sf::Keyboard::Key::D ){
        mIsMovingRight = isPressed;
        mPlayer.setFillColor(sf::Color::Green);
    }
        
    
    

}

void Game::update(sf::Time deltaTime){
    
    sf::Vector2f movement(0.f,0.f);
    
    if(mIsMovingUp)
        movement.y-=10.f*deltaTime.asSeconds();
    if(mIsMovingDown)
        movement.y+=10.f*deltaTime.asSeconds();
    if(mIsMovingLeft)
        movement.x-=10.f*deltaTime.asSeconds();
    if(mIsMovingRight)
        movement.x+=10.f*deltaTime.asSeconds();
    mPlayer.move(movement);
}


void Game::render(){
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}


Game::~Game(){

}
