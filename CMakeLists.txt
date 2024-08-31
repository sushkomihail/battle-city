cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("BattleCity")

set(CMAKE_CXX_STANDARD 17)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (BattleCity
"src/Main.cpp"
"src/Main.h"
"src/game/Game.cpp"
"src/Utils/ResourcesLoader.cpp"
"src/Engine/Objects/Object.cpp"
"src/Engine/Objects/Object.h"
"src/Game/Map.cpp"
"src/Game/Map.h"
"src/Game/Brick/Brick.cpp"
"src/Game/Brick/Brick.h"
"src/Game/Steel/Steel.cpp"
"src/Game/Steel/Steel.h"
"src/Game/Map.cpp"
"src/Game/Eagle.cpp"
"src/Game/Eagle.h"
"src/Game/TankColor.h"
"src/Engine/Direction.h"
"src/Game/Input.cpp"
"src/Game/Input.h"
"src/Engine/Objects/DynamicObject.cpp"
"src/Engine/Objects/DynamicObject.h"
"src/Game/TankType.h"
"src/Game/TankView.cpp"
"src/Game/TankView.h"
"src/Game/Tank.cpp"
"src/Game/Tank.h"
"src/Engine/Collider.cpp"
"src/Engine/Collider.h"
#"src/Game/Projectile.cpp"
#"src/Game/Projectile.h"
"src/Game/World.cpp"
"src/Game/World.h"
"src/Game/IDestructible.h"
"src/Game/Brick/BrickTile.cpp"
"src/Game/Brick/BrickTile.h"
"src/Engine/Objects/CompositeObject.h"
"src/Game/TileLocation.h"
"src/Game/Steel/SteelTile.cpp"
"src/Game/Steel/SteelTile.h"
"src/Game/Water.cpp"
"src/Game/Water.h"
"src/Game/Bush.cpp"
"src/Game/Bush.h"
"src/Game/Ice.cpp"
"src/Game/Ice.h"
"src/Game/Tile.cpp"
"src/Game/Tile.h"
)

set(SFML_DIR C:/SFML/SFML-2.6.1-VS/lib/cmake/SFML)

find_package(SFML COMPONENTS system window graphics audio REQUIRED)

include_directories(C:/SFML/SFML-2.6.1-VS/include/SFML)

target_link_libraries(BattleCity sfml-system sfml-window sfml-graphics sfml-audio)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BattleCity PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
