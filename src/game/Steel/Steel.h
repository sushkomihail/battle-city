#ifndef STEEL_H
#define STEEL_H

#include "SteelTile.h"
#include "../../Engine/Objects/CompositeObject.h"

class Steel final : public CompositeObject<SteelTile> {
public:
    Steel(const std::vector<TileLocation> &tileLocations);

private:
    static constexpr int OBJECT_SIZE = 64;

};

#endif
