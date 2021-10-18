#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/Paddle.hpp"
#include "../include/Ball.hpp"


sf::RenderWindow window(sf::VideoMode(500, 500), "Pong!", sf::Style::Close | sf::Style::Titlebar);
sf::Event event;

unsigned int eScore = 0;
unsigned int pScore = 0;


int main() {
    Paddle playerPaddle(30.0f, 150.0f, true, 0.f, 250.0f);
    Paddle enemyPaddle(30.0f, 150.0f, false, 500 - 30, 250.0f);

    sf::Text eScoreLabel;
    sf::Font scoreFont;
    scoreFont.loadFromFile("../fonts/arial.ttf");
    eScoreLabel.setFont(scoreFont);
    eScoreLabel.setCharacterSize(100);
    eScoreLabel.setFillColor(sf::Color::White);

    eScoreLabel.setPosition(380, 0);

    sf::Text pScoreLabel;
    pScoreLabel.setFont(scoreFont);
    pScoreLabel.setCharacterSize(100);
    eScoreLabel.setFillColor(sf::Color::White);

    pScoreLabel.setPosition(80, 0);

    Ball ball(15.0, 250.0, 250.0);

    window.setFramerateLimit(120);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case event.Closed:
                    window.close();
            }
        }

        window.clear();
        playerPaddle.draw();
        playerPaddle.update(event);
        enemyPaddle.draw();
        enemyPaddle.update(event);

        eScoreLabel.setString(std::to_string(eScore));
        window.draw(eScoreLabel);

        pScoreLabel.setString(std::to_string(pScore));
        window.draw(pScoreLabel);

        ball.draw();
        ball.update(playerPaddle, enemyPaddle);

        window.display();

    }
}
