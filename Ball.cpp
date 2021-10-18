#include "../include/Ball.hpp"


Ball::Ball(float radius, float x, float y) : radius(radius) {
    this -> body = sf::CircleShape(radius);
    this -> body.setPosition(x, y);
}


void Ball::draw() {
    window.draw(this -> body);
}


void Ball::update(Paddle& paddle1, Paddle& paddle2) {
    static float velx = 2.0;
    static float vely = 2.4;

    if (this -> body.getGlobalBounds().intersects(paddle1.getBody().getGlobalBounds())) {
        velx = -velx;
    } else if (this -> body.getGlobalBounds().intersects(paddle2.getBody().getGlobalBounds())) {
        velx = -velx;
    } else if (this -> body.getPosition().y >= 500 - this -> radius) {
        vely = -vely;
    } else if (this -> body.getPosition().y <= 0) {
        vely = -vely;
    } else if (this -> body.getPosition().x > 500) {
        this -> body.setPosition(250, 250);
        ++pScore;
    } else if (this -> body.getPosition().x < 0) {
        this -> body.setPosition(250, 250);
        ++eScore;
    }

    this -> body.move(velx, vely);
}
