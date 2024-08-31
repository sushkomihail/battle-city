#ifndef STEELTILE_H
#define STEELTILE_H

#include <string>
#include <unordered_map>
#include <Graphics/Texture.hpp>

#include "../Tile.h"
#include "../../Utils/ResourcesLoader.h"

class SteelTile : public Tile {
public:
    SteelTile();

private:
    inline static const std::string SPRITE_SHEET = "res/SpriteSheets/Steel.png";

    inline static std::unordered_map<int, sf::Texture*> textures {
                {1024, ResourcesLoader::loadTexture(SPRITE_SHEET, 0, 0, 64, 64)}
    };
};



#endif //STEELTILE_H
