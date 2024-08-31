#ifndef TANKVIEW_H
#define TANKVIEW_H

#include <unordered_map>
#include <Graphics/Texture.hpp>

#include "TankType.h"
#include "TankColor.h"
#include "../Engine/Objects/Object.h"

class TankView {
public:
    TankView(TankType type, TankColor color, Object *tankObject);
    ~TankView();

    void setTexture(const sf::Vector2i *directionAxes);

private:
    inline static const std::string SPRITE_SHEET = "res/SpriteSheet.png";

    const int TEXTURE_SIZE = 64;

    Object* tankObject {};

    std::unordered_map<TankColor, sf::Vector2i> coordsOfTexturesBlocks {
            {YELLOW, {0, 0}},
            {GREY, {512, 0}},
            {GREEN, {0, 512}},
            {RED, {512, 512}}
    };
    std::unordered_map<sf::Vector2i, sf::Texture*> texturesInMoveDirection;
    sf::Texture *texture {};

    void initializeTexturesInMoveDirections(TankType type, TankColor color);
};

#endif // TANKVIEW_H
