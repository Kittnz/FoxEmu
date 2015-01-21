/*
 * Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FOXEMU_SYSTEMCONFIG_H
#define FOXEMU_SYSTEMCONFIG_H

#include "Define.h"
#include "revision.h"

#if PLATFORM == PLATFORM_WINDOWS
# ifdef _WIN64
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Win64)"
# else
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Win32)"
# endif
#else
#  define _FULLVERSION "FoxEmu rev. " VER_PRODUCTVERSION_STR " (Unix)"
#endif

#define CLIENTVERSION "Version 4.20.0.315 [PUBLIC]"

#endif
