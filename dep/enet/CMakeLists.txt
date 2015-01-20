# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB sources_enet *.cpp *.h)

set(enet_STAT_SRCS
    ${sources_enet}
)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/server/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if (WIN32)
    set(enet_win_libs odbc32 odbccp32 winmm ws2_32)
endif()

add_library(enet STATIC ${enet_STAT_SRCS})

set_target_properties(enet PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(enet
    ${enet_win_libs}
)
