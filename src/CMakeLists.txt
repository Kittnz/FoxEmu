# Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

add_subdirectory(genrev)

if (LOGONSERVER)
    add_subdirectory(logonserver)
endif()

if (GAMENODE)
    add_subdirectory(gamenode)
    add_subdirectory(game)
#    add_subdirectory(scripts)
endif()
