#include "Map.h"

#include <iostream>

#include "Bush.h"
#include "Brick/Brick.h"
#include "Steel/Steel.h"
#include "Water.h"
#include "Eagle.h"
#include "Ice.h"

Map::Map(const int num): objects({}) {
    try {
        const std::vector<std::string> &map = ResourcesLoader::loadMap(num);
        initObjects(map);
    } catch (const std::exception &exception) {
        std::cout << "Map::Map->loadMap: " << exception.what() << std::endl;
    }
}

Map::~Map() {
    for (const auto &[coords, object] : objects) {
        delete object;
    }
}

sf::Vector2i Map::getCellOfPosition(const sf::Vector2i &position) {
    int x = static_cast<int>(position.x) / BLOCK_SIZE;
    int y = static_cast<int>(position.y) / BLOCK_SIZE;
    return {x, y};
}

Object *Map::getCellObject(const sf::Vector2i &coords) const {
    if (objects.count(coords) > 0) {
        return objects.at(coords);
    }

    return nullptr;
}

std::vector<Object*> Map::getObjectsInArea(const sf::Vector2i &leftTop, const sf::Vector2i &rightBottom) const {
    std::vector<Object*> objects;

    // std::cout << "lt: " << leftTop.x << ", " << leftTop.y << " rb: " << rightBottom.x << ", " << rightBottom.y << std::endl;

    for (int i = leftTop.y; i <= rightBottom.y; i++) {
        for (int j = leftTop.x; j <= rightBottom.x; j++) {
            sf::Vector2i cell = {j, i};

            if (this->objects.count(cell) > 0) {
                objects.push_back(this->objects.at(cell));
            }
        }
    }

    return objects;
}

std::vector<Object *> Map::getObjectsInArea(const sf::Vector2i &leftTop, const sf::Vector2i &rightBottom,
    const std::function<bool(const sf::Vector2i &objectPosition)> &condition) const {
    std::vector<Object*> objects;

    // std::cout << "lt: " << leftTop.x << ", " << leftTop.y << " rb: " << rightBottom.x << ", " << rightBottom.y << std::endl;

    for (int i = leftTop.y; i <= rightBottom.y; i++) {
        for (int j = leftTop.x; j <= rightBottom.x; j++) {
            sf::Vector2i cell = {j, i};

            if (this->objects.count(cell) > 0) {
                Object *object = this->objects.at(cell);

                if (condition(object->getPosition())) {
                    objects.push_back(object);
                }
            }
        }
    }

    return objects;
}

void Map::render(sf::RenderWindow &window) {
    for (auto& [coords, object] : objects) {
        const int x = coords.x * BLOCK_SIZE;
        const int y = coords.y * BLOCK_SIZE;
        object->getPosition() = sf::Vector2i(x, y);
        object->render(window);
    }
}

bool Map::isCorrect(const std::vector<std::string> &map) {
    if (map.size() > BLOCKS_LIMIT_ON_AXIS) {
        return false;
    }

    auto longer = [&](const std::string &a, const std::string &b) {
        return a.length() < b.length();
    };

    const std::string &longestRow = *std::max_element(map.begin(), map.end(), longer);
    return longestRow.length() <= BLOCKS_LIMIT_ON_AXIS;
}

Object* Map::createObject(const char type) {
    switch (type) {
        case '0':
            return new Brick({LEFT_BOTTOM});
        case '1':
            return new Brick({RIGHT_BOTTOM});
        case '2':
            return new Brick({LEFT_TOP, LEFT_BOTTOM});
        case '3':
            return new Brick({RIGHT_TOP, RIGHT_BOTTOM});
        case '4':
            return new Brick({LEFT_TOP, RIGHT_TOP});
        case '5':
            return new Brick({LEFT_BOTTOM, RIGHT_BOTTOM});
        case '6':
            return new Brick({LEFT_TOP, LEFT_BOTTOM, RIGHT_TOP, RIGHT_BOTTOM});
        case '7':
            return new Steel({LEFT_TOP, LEFT_BOTTOM});
        case '8':
            return new Steel({RIGHT_TOP, RIGHT_BOTTOM});
        case '9':
            return new Steel({LEFT_TOP, RIGHT_TOP});
        case 'A':
            return new Steel({LEFT_BOTTOM, RIGHT_BOTTOM});
        case 'B':
            return new Steel({LEFT_TOP, LEFT_BOTTOM, RIGHT_TOP, RIGHT_BOTTOM});
        case 'C':
            return new Water;
        case 'D':
            return new Bush;
        case 'E':
            return new Ice;
        case 'F':
            return new Eagle;
        default:
            throw std::runtime_error("There is no object of type '" + type + '\'');
    }
}

void Map::initObjects(const std::vector<std::string> &map) {
    if (!isCorrect(map)) {
        return;
    }

    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].length(); j++) {
            if (map[i][j] != '-') {
                try {
                    objects.emplace(sf::Vector2i(j, i), createObject(map[i][j]));
                } catch (const std::exception &exception) {
                    std::cout << "Map::initObjects->createObject: " << exception.what() << std::endl;
                }
            }
        }
    }
}
