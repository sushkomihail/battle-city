#ifndef WATER_H
#define WATER_H

#include "../Engine/Objects/Object.h"

class Water final : public Object {
public:
    explicit Water();

private:
    static constexpr unsigned OBJECT_SIZE = 64;
};

#endif //WATER_H
