# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    SET(CMAKE_CXX_FLAGS "-g -std=c++11 -pedantic")
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    SET(CMAKE_CXX_FLAGS "/EHsc") #So it doesn't constantly throw warnings
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    IF (WIN32)
        SET(CMAKE_CXX_FLAGS "/Qstd=c++11")
    ELSE()
        SET(CMAKE_CXX_FLAGS "-std=c++11")
    ENDIF()
ELSEIF(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    SET(CMAKE_CXX_FLAGS "-std=c++11")
ENDIF()

file(GLOB gamenode_files *.cpp *.h)

set(gamenode_SRCS
    ${gamenode_SRCS}
    ${gamenode_files}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/enet
    ${CMAKE_SOURCE_DIR}/dep/intlib
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/game
    ${CMAKE_SOURCE_DIR}/src/game/AI
    ${CMAKE_SOURCE_DIR}/src/game/Chat
    ${CMAKE_SOURCE_DIR}/src/game/Collision
    ${CMAKE_SOURCE_DIR}/src/game/Entities
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Champion
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Fountain
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Item
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Minion
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Object
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Projectile
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Turret
    ${CMAKE_SOURCE_DIR}/src/game/Entities/Unit
    ${CMAKE_SOURCE_DIR}/src/game/Gamenode
    ${CMAKE_SOURCE_DIR}/src/game/Handlers
    ${CMAKE_SOURCE_DIR}/src/game/Logger
    ${CMAKE_SOURCE_DIR}/src/game/Map
    ${CMAKE_SOURCE_DIR}/src/game/Map/Zones
    ${CMAKE_SOURCE_DIR}/src/game/Misc
    ${CMAKE_SOURCE_DIR}/src/game/Movement
    ${CMAKE_SOURCE_DIR}/src/game/Notifiers
    ${CMAKE_SOURCE_DIR}/src/game/Packets
    ${CMAKE_SOURCE_DIR}/src/game/Spells
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src/shared
)

if (WIN32)
    if (MSVC)
        set(gamenode_SRCS
            ${gamenode_SRCS}
            gamenode.rc
        )
    endif()
endif()

add_executable(gamenode
    ${gamenode_SRCS}
)

add_dependencies(gamenode revision.h)

target_link_libraries(gamenode
    enet
    intlib
    raf
    game
    ${Boost_LIBRARIES}
)

if ( WIN32 )
    if ( MSVC )
        add_custom_command(TARGET gamenode
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gamenode.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
        )
    elseif ( MINGW )
        add_custom_command(TARGET gamenode
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gamenode.conf.dist ${CMAKE_BINARY_DIR}/bin/
        )
    endif()
endif()

if ( UNIX )
    install(TARGETS gamenode DESTINATION bin)
    install(FILES gamenode.conf.dist DESTINATION ${CONF_DIR})
elseif ( WIN32 )
    install(TARGETS gamenode DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES gamenode.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
