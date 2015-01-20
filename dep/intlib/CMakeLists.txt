# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB intlib_sources *.cpp *.h)

set(intlib_STAT_SRCS
    ${intlib_sources}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(intlib STATIC ${intlib_STAT_SRCS})

set_target_properties(intlib PROPERTIES LINKER_LANGUAGE CXX)
