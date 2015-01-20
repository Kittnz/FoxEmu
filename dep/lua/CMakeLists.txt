# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB lua_sources *.cpp *.h *.hpp)

set(lua_STAT_SRCS
    ${lua_sources}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(lua STATIC ${lua_STAT_SRCS})

set_target_properties(lua PROPERTIES LINKER_LANGUAGE CXX)
