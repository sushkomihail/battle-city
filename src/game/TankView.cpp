#include "TankView.h"
#include "../Utils/ResourcesLoader.h"

using namespace sf;

TankView::TankView(const TankType type, const TankColor color, Object *tankObject): texturesInMoveDirection() {
    this->tankObject = tankObject;
    initializeTexturesInMoveDirections(type, color);
    setTexture(new Vector2i(0, -1));
}

TankView::~TankView() {
    delete tankObject;
    delete texture;
}

void TankView::setTexture(const sf::Vector2i *directionAxes) {
    texture = &texturesInMoveDirection.at(*directionAxes)[0];
    tankObject->setTexture(texture);
}

void TankView::initializeTexturesInMoveDirections(const TankType type, const TankColor color) {
    auto [x, y] = coordsOfTexturesBlocks.at(color);
    y += type * TEXTURE_SIZE;

    texturesInMoveDirection[{0, -1}] = new Texture [] {
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x, y, TEXTURE_SIZE, TEXTURE_SIZE),
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
    };
    texturesInMoveDirection[{0, 1}] = new Texture [] {
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 4 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 5 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
    };
    texturesInMoveDirection[{-1, 0}] = new Texture [] {
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 2 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 3 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
    };
    texturesInMoveDirection[{1, 0}] = new Texture [] {
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 6 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
        *ResourcesLoader::loadTexture(SPRITE_SHEET, x + 7 * TEXTURE_SIZE, y, TEXTURE_SIZE, TEXTURE_SIZE),
    };
}
