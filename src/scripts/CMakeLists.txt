# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE sources_Champions Champions/*.cpp Champions/*.h)
file(GLOB_RECURSE sources_Commands Commands/*.cpp Commands/*.h)
file(GLOB_RECURSE sources_Maps Maps/*.cpp Maps/*.h)

# Create scripts-library
set(scripts_STAT_SRCS
    ${scripts_STAT_SRCS}
    ${sources_Champions}
    ${sources_Commands}
    ${sources_Maps}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Champions
    ${CMAKE_CURRENT_SOURCE_DIR}/Commands
    ${CMAKE_CURRENT_SOURCE_DIR}/Maps
)

add_library(scripts STATIC
    ${scripts_STAT_SRCS}
)
