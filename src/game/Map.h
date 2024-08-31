#ifndef MAP_H
#define MAP_H

#include <functional>
#include <unordered_map>
#include <vector>
#include <Graphics/RenderWindow.hpp>

template<>
struct std::hash<sf::Vector2i> {
    size_t operator()(const sf::Vector2i &vector) const noexcept {
        return hash<string>()(vector.x + " " + vector.y);
    }
};

class Object;

class Map {
public:
    static constexpr unsigned short WIDTH = 832;
    static constexpr unsigned short HEIGHT = 832;

    explicit Map(int num);
    ~Map();

    static sf::Vector2i getCellOfPosition(const sf::Vector2i &position);
    Object *getCellObject(const sf::Vector2i &coords) const;
    std::vector<Object*> getObjectsInArea(const sf::Vector2i &leftTop, const sf::Vector2i &rightBottom) const;
    std::vector<Object*> getObjectsInArea(const sf::Vector2i &leftTop, const sf::Vector2i &rightBottom,
                                          const std::function<bool(const sf::Vector2i &objectPosition)> &condition) const;
    void render(sf::RenderWindow &window);

private:
    static constexpr int BLOCK_SIZE = 64;
    static constexpr unsigned BLOCKS_LIMIT_ON_AXIS = 13;

    std::unordered_map<sf::Vector2i, Object*> objects;

    static bool isCorrect(const std::vector<std::string> &map);
    static Object* createObject(char type);

    void initObjects(const std::vector<std::string> &map);
};

#endif
