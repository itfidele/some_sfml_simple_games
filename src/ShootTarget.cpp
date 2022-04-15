

#include "include/ShootTarget.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowStyle.hpp"
#include <iostream>


ShootTarget::ShootTarget():mWindow(sf::VideoMode(640,400),"Shoot Target with mouse",sf::Style::Default){
    mWindow.setFramerateLimit(60);
    hoop.setFillColor(sf::Color::Black);
    hoop.setOutlineThickness(2.f);
    hoop.setOutlineColor(sf::Color::Blue);
    hoop.setRadius(50.f);
    hoop.setPosition(sf::Vector2f(0,10.f));

    // ball
    ball.setRadius(20.f);
    ball.setFillColor(sf::Color::Red);
    ball.setPosition(sf::Vector2f(0,mWindow.getSize().y - ball.getRadius()*3));
}

void ShootTarget::run(){

    while (mWindow.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void ShootTarget::processEvents(){

    sf::Event event;

    while (mWindow.pollEvent(event)) {
        
        switch (event.type) {

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
    

}

void ShootTarget::update(){
    
    if (!isShoot) {
        ball.setPosition(sf::Mouse::getPosition(mWindow).x,ball.getPosition().y);
    }
    else{
        ball.move(0,-5.f);
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !isShoot) {
        isShoot = true;
    }


    if (ball.getGlobalBounds().intersects(hoop.getGlobalBounds())) {
        score++;
        std::cout<<score<<std::endl;
    }
    // Collision
    if (ball.getPosition().y <= 0 || ball.getGlobalBounds().intersects(hoop.getGlobalBounds())) {
        isShoot = false;
        ball.setPosition(ball.getPosition().x,mWindow.getSize().y - ball.getRadius()*3);
    }


    if(hoop.getPosition().x <= 0 )
        direction =1;
    else if (hoop.getPosition().x + hoop.getRadius()*2 >= mWindow.getSize().x)
        direction =0;

    if (direction==0) {
        hoop.move(-5.f,0);
    }
    else{
        hoop.move(5.f,0);
    }
}

void ShootTarget::render(){
    mWindow.clear(sf::Color::White);
    mWindow.draw(hoop);
    mWindow.draw(ball);
    mWindow.display();
}


ShootTarget::~ShootTarget(){
    
}