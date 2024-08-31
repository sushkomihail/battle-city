#include "Input.h"

#include <algorithm>
#include <vector>

using namespace std;
using namespace sf;

Input::Input(
    const Keyboard::Key forward,
    const Keyboard::Key backward,
    const Keyboard::Key left,
    const Keyboard::Key right,
    const Keyboard::Key shoot
    ) {
    this->forward = forward;
    this->backward = backward;
    this->left = left;
    this->right = right;
    this->shoot = shoot;


    movementAxes = new Vector2i;
}

Input::~Input() {
    delete movementAxes;
}

Vector2i *Input::getMovementAxes() {
    movementAxes->x = 0;
    movementAxes->y = 0;

    processMovementInput(forward, 0, -1);
    processMovementInput(backward, 0, 1);
    processMovementInput(left, -1, 0);
    processMovementInput(right, 1, 0);

    return movementAxes;
}

bool Input::canShoot() const {
    return Keyboard::isKeyPressed(shoot);
}

void Input::processMovementInput(const Keyboard::Key key, const int targetXAxis, const int targetYAxis) {
    if (Keyboard::isKeyPressed(key)) {
        if (find(pressedMovementKeys.begin(), pressedMovementKeys.end(), key) == pressedMovementKeys.end()) {
            pressedMovementKeys.push_back(key);
        }

        const Keyboard::Key lastKey = pressedMovementKeys[pressedMovementKeys.size() - 1];

        if (key == lastKey) {
            movementAxes->x = targetXAxis;
            movementAxes->y = targetYAxis;
        }
    }
    else {
        if (find(pressedMovementKeys.begin(), pressedMovementKeys.end(), key) != pressedMovementKeys.end()) {
            for (auto it = pressedMovementKeys.begin(); it != pressedMovementKeys.end(); ++it) {
                if (*it == key) {
                    pressedMovementKeys.erase(it);
                    break;
                }
            }
        }
    }
}
