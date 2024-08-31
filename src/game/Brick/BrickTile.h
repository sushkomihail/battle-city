#ifndef BRICKTILE_H
#define BRICKTILE_H

#include <string>
#include <unordered_map>
#include <Graphics/Texture.hpp>

#include "../Tile.h"
#include "../../Utils/ResourcesLoader.h"

class BrickTile : public Tile {
public:
    BrickTile();

private:
    inline static const std::string SPRITE_SHEET = "res/SpriteSheets/Brick.png";
    inline static const std::unordered_map<int, sf::Texture*> textures {
            {0, ResourcesLoader::loadTexture(SPRITE_SHEET, 0, 0, 32, 32)},
            {1, ResourcesLoader::loadTexture(SPRITE_SHEET, 32, 0, 32, 32)},
            {2, ResourcesLoader::loadTexture(SPRITE_SHEET, 64, 0, 32, 32)},
            {5, ResourcesLoader::loadTexture(SPRITE_SHEET, 96, 0, 32, 32)},
            {9, ResourcesLoader::loadTexture(SPRITE_SHEET, 128, 0, 32, 32)},
            {3, ResourcesLoader::loadTexture(SPRITE_SHEET, 160, 0, 32, 32)},
            {14, ResourcesLoader::loadTexture(SPRITE_SHEET, 192, 0, 32, 32)},
            {6, ResourcesLoader::loadTexture(SPRITE_SHEET, 224, 0, 32, 32)},
            {11, ResourcesLoader::loadTexture(SPRITE_SHEET, 256, 0, 32, 32)},
            {10, ResourcesLoader::loadTexture(SPRITE_SHEET, 288, 0, 32, 32)},
            {7, ResourcesLoader::loadTexture(SPRITE_SHEET, 320, 0, 32, 32)},
            {8, ResourcesLoader::loadTexture(SPRITE_SHEET, 352, 0, 32, 32)},
            {12, ResourcesLoader::loadTexture(SPRITE_SHEET, 384, 0, 32, 32)},
            {15, ResourcesLoader::loadTexture(SPRITE_SHEET, 416, 0, 32, 32)},
            {16, ResourcesLoader::loadTexture(SPRITE_SHEET, 448, 0, 32, 32)},
            {17, ResourcesLoader::loadTexture(SPRITE_SHEET, 480, 0, 32, 32)}
    };
};



#endif //BRICKTILE_H
