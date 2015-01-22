# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_AI AI/*.cpp AI/*.h)
file(GLOB_RECURSE sources_Chat Chat/*.cpp Chat/*.h)
file(GLOB_RECURSE sources_Collision Collision/*.cpp Collision/*.h)
file(GLOB_RECURSE sources_Entities Entities/*.cpp Entities/*.h)
file(GLOB_RECURSE sources_Gamenode Gamenode/*.cpp Gamenode/*.h)
file(GLOB_RECURSE sources_Handlers Handlers/*.cpp Handlers/*.h)
file(GLOB_RECURSE sources_Logger Logger/*.cpp Logger/*.h)
file(GLOB_RECURSE sources_Map Map/*.cpp Map/*.h)
file(GLOB_RECURSE sources_Misc Misc/*.cpp Misc/*.h)
file(GLOB_RECURSE sources_Movement Movement/*.cpp Movement/*.h)
file(GLOB_RECURSE sources_Notifiers Notifiers/*.cpp Notifiers/*.h)
file(GLOB_RECURSE sources_Packets Packets/*.cpp Packets/*.h)
file(GLOB_RECURSE sources_Spells Spells/*.cpp Spells/*.h)

# Create game-libary

set(game_STAT_SRCS
    ${game_STAT_SRCS}
    ${sources_AI}
    ${sources_Chat}
    ${sources_Collision}
    ${sources_Entities}
    ${sources_Gamenode}
    ${sources_Handlers}
    ${sources_Logger}
    ${sources_Map}
    ${sources_Misc}
    ${sources_Movement}
    ${sources_Notifiers}
    ${sources_Packets}
    ${sources_Spells}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/enet
    ${CMAKE_SOURCE_DIR}/dep/intlib
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/AI
    ${CMAKE_CURRENT_SOURCE_DIR}/Chat
    ${CMAKE_CURRENT_SOURCE_DIR}/Collision
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Champion
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Fountain
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Item
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Minion
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Object
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Projectile
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Turret
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/Unit
    ${CMAKE_CURRENT_SOURCE_DIR}/Gamenode
    ${CMAKE_CURRENT_SOURCE_DIR}/Handlers
    ${CMAKE_CURRENT_SOURCE_DIR}/Logger
    ${CMAKE_CURRENT_SOURCE_DIR}/Map
    ${CMAKE_CURRENT_SOURCE_DIR}/Map/Zones
    ${CMAKE_CURRENT_SOURCE_DIR}/Misc
    ${CMAKE_CURRENT_SOURCE_DIR}/Movement
    ${CMAKE_CURRENT_SOURCE_DIR}/Notifiers
    ${CMAKE_CURRENT_SOURCE_DIR}/Packets
    ${CMAKE_CURRENT_SOURCE_DIR}/Spells
    ${CMAKE_SOURCE_DIR}/src/shared
)

add_library(game STATIC
    ${game_STAT_SRCS}
)

target_link_libraries(game
    enet
    intlib
    raf
    ${Boost_LIBRARIES}
)

add_dependencies(game revision.h)
