#ifndef EAGLE_H
#define EAGLE_H

#include "../Engine/Objects/Object.h"
#include "../Utils/ResourcesLoader.h"

class Eagle final : public Object {
public:
    Eagle();

private:
    inline static const std::string SPRITE_SHEET = "res/SpriteSheets/Eagle.png";

     inline static sf::Texture *texture =
         ResourcesLoader::loadTexture(SPRITE_SHEET, 0, 0, 64, 64);
};

#endif
