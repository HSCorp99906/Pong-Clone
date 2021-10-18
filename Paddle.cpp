#include "../include/Paddle.hpp"


Paddle::Paddle(float scalex, float scaley, bool isPlayer, float x, float y) {
    this -> body = sf::RectangleShape(sf::Vector2f(scalex, scaley));
    this -> isPlayer = isPlayer;
    this -> body.setPosition(x, y);
}


void Paddle::update(sf::Event& event) {
    if (this -> isPlayer) {
        switch (event.type) {
            case event.KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        this -> body.move(0.0f, -1.4f);
                        break;
                    case sf::Keyboard::Down:
                        this -> body.move(0.0f, 1.4f);
                        break;
                }
        }
    } else {
        static bool movingUp = true;

        float speeds[4] = {30.3, 5.4, 6.2, 9.4};

        srand(time(NULL));

        if (movingUp) {
            if (this -> body.getPosition().y <= 0) {
                movingUp = false;
            } else {
                this -> body.move(0.0f, -speeds[rand() % 3]);
            }
        } else {
            if (this -> body.getPosition().y >= 500) {
                movingUp = true;
            } else {
                this -> body.move(0.0f, speeds[rand() % 3]);
            }
        }
    }
}


void Paddle::draw() {
    window.draw(this -> body);
}


const sf::RectangleShape& Paddle::getBody() {
    return this -> body;
}
