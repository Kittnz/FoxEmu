# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-g -std=c++11 -pedantic")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(CMAKE_CXX_FLAGS "/EHsc") #So it doesn't constantly throw warnings
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    if (WIN32)
        set(CMAKE_CXX_FLAGS "/Qstd=c++11")
    else ()
        set(CMAKE_CXX_FLAGS "-std=c++11")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

file(GLOB logonserver_files *.cpp *.h)

set(logonserver_SRCS
    ${logonserver_SRCS}
    ${logonserver_files}
)

include_directories(
    ${CMAKE_BINARY_DIR}
    ${CMAKE_SOURCE_DIR}/dep/raf
    ${CMAKE_SOURCE_DIR}/src/shared
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if ( WIN32 )
    if ( MSVC )
        set(logonserver_SRCS
            ${logonserver_SRCS}
            logonserver.rc
        )
    endif ()
endif()

add_executable(logonserver
    ${logonserver_SRCS}
)

add_dependencies(logonserver revision.h)

target_link_libraries(logonserver
    raf
    ${Boost_LIBRARIES}
)

if ( WIN32 )
    if ( MSVC )
        add_custom_command(TARGET logonserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/logonserver.conf.dist ${CMAKE_BINARY_DIR}/bin/$(ConfigurationName)/
        )
    elseif ( MINGW )
        add_custom_command(TARGET logonserver
            POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/logonserver.conf.dist ${CMAKE_BINARY_DIR}/bin/
        )
    endif()
endif()

if ( UNIX )
    install(TARGETS logonserver DESTINATION bin)
    install(FILES logonserver.conf.dist DESTINATION ${CONF_DIR})
elseif ( WIN32 )
    install(TARGETS logonserver DESTINATION "${CMAKE_INSTALL_PREFIX}")
    install(FILES logonserver.conf.dist DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif()
