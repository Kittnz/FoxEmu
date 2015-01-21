# Copyright (C) 2014 FoxEmu <http://www.foxemu.ovh/>
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

file(GLOB gameserver_files *.cpp *.h)

set(gameserver_SRCS
    ${gameserver_SRCS}
    ${gameserver_files}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/enet
    ${CMAKE_SOURCE_DIR}/dep/intlib
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if (WIN32)
    if (MSVC)
        set(gameserver_SRCS
            ${gameserver_SRCS}
            gameserver.rc
        )
    endif()
endif()

add_executable(gameserver
    ${gameserver_SRCS}
)

add_dependencies(gameserver revision.h)

target_link_libraries(gameserver
    enet
    intlib
    raf
    ${Boost_LIBRARIES}
)

if ( WIN32 )
    if ( MSVC )
        add_custom_command(TARGET gameserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gameserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
        )
    elseif ( MINGW )
        add_custom_command(TARGET gameserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gameserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
        )
    endif()
endif()

if( UNIX )
    install(TARGETS gameserver DESTINATION bin)
    install(FILES gameserver.conf.dist DESTINATION ${CONF_DIR})
elseif( WIN32 )
    install(TARGETS gameserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES gameserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
