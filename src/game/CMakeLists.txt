# Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_AI AI/*.cpp AI/*.h)
#file(GLOB_RECURSE sources_Entities Entities/*.cpp Entities/*.h)

# Create game-libary

set(game_STAT_SRCS
    ${game_STAT_SRCS}
    ${sources_AI}
    #${sources_Entities}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/AI
    #${CMAKE_CURRENT_SOURCE_DIR}/Entities
    #${CMAKE_CURRENT_SOURCE_DIR}/Entities/Champions
)

add_library(game STATIC
    ${game_STAT_SRCS}
)

add_dependencies(game revision.h)
