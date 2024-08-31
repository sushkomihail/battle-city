#ifndef INPUT_H
#define INPUT_H

#include <Window/Keyboard.hpp>
#include <vector>
#include <System/Vector2.hpp>


class Input {
public:
    Input(
        sf::Keyboard::Key forward,
        sf::Keyboard::Key backward,
        sf::Keyboard::Key left,
        sf::Keyboard::Key right,
        sf::Keyboard::Key shoot
        );
    ~Input();

    sf::Vector2i* getMovementAxes();
    bool canShoot() const;

private:
    sf::Keyboard::Key forward;
    sf::Keyboard::Key backward;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key shoot;

    std::vector<sf::Keyboard::Key> pressedMovementKeys;
    sf::Vector2i *movementAxes;

    void processMovementInput(sf::Keyboard::Key key, int targetXAxis, int targetYAxis);
};

#endif
