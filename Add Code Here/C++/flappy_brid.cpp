#include <SFML/Graphics.hpp>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float GRAVITY = 0.3f;
const float JUMP_FORCE = 7.0f;
const float PIPE_SPEED = 2.0f;

class Bird {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Bird() {
        shape.setRadius(20);
        shape.setFillColor(sf::Color::Green);
        shape.setPosition(100, SCREEN_HEIGHT / 2);
        velocity = sf::Vector2f(0, 0);
    }

    void jump() {
        velocity.y = -JUMP_FORCE;
    }

    void update() {
        velocity.y += GRAVITY;
        shape.move(0, velocity.y);
    }
};

class Pipe {
public:
    sf::RectangleShape shape;
    bool passed;

    Pipe(float x) {
        shape.setSize(sf::Vector2f(80, 400));
        shape.setFillColor(sf::Color::Cyan);
        shape.setPosition(x, 0);
        passed = false;
    }

    void move() {
        shape.move(-PIPE_SPEED, 0);
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Flappy Bird");
    Bird bird;
    std::vector<Pipe> pipes;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) {
                    bird.jump();
                }
            }
        }

        bird.update();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            bird.jump();
        }

        if (pipes.empty() || pipes.back().shape.getPosition().x < SCREEN_WIDTH - 300) {
            pipes.emplace_back(SCREEN_WIDTH);
        }

        for (auto& pipe : pipes) {
            pipe.move();
            if (pipe.shape.getPosition().x + pipe.shape.getSize().x < bird.shape.getPosition().x && !pipe.passed) {
                pipe.passed = true;
                // Increase score
            }
        }

        // Check for collisions with pipes or ground
        for (auto& pipe : pipes) {
            if (bird.shape.getGlobalBounds().intersects(pipe.shape.getGlobalBounds()) ||
                bird.shape.getPosition().y + bird.shape.getRadius() >= SCREEN_HEIGHT) {
                // Game over logic
                // Reset bird position and clear pipes
                bird.shape.setPosition(100, SCREEN_HEIGHT / 2);
                bird.velocity = sf::Vector2f(0, 0);
                pipes.clear();
            }
        }

        window.clear();
        window.draw(bird.shape);
        for (const auto& pipe : pipes) {
            window.draw(pipe.shape);
        }
        window.display();
    }

    return 0;
}
