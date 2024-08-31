#ifndef IDESTRUCTIBLE_H
#define IDESTRUCTIBLE_H

#include <System/Vector2.hpp>

class IDestructible {
public:
    virtual ~IDestructible() = default;

    virtual void destruct(const sf::Vector2i &contactPosition) = 0;
    virtual bool isDestructedAtPosition(const sf::Vector2i *position) = 0;
};

#endif //IDESTRUCTIBLE_H
