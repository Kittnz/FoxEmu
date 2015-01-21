/*
IntWars playground server for League of Legends protocol testing
Copyright (C) 2012  Intline9 <Intline9@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Stdafx.h"
#include "Game.h"
#include "RAFManager.h"
#include "Inibin.h"
#include "ItemManager.h"
#include "Logger.h"
#include "Pathfinder.h"

#define SERVER_HOST ENET_HOST_ANY
#define SERVER_PORT 5119
#define SERVER_KEY "17BLOhi6KZsTtldTsizvHg=="

#define SERVER_VERSION "0.2.0"

int main(int argc, char ** argv)
{
	printf("Yorick %s\n", SERVER_VERSION);

	Logger::instance().setLogFile("../../log.html", false, true);

	CORE_INFO(">> Loading RAF files ...");

    if (!RAFManager::getInstance()->init("filearchives"))
    {
        CORE_ERROR("Couldn't load RAF files. Make sure you have a 'filearchives' directory in the server's root directory. This directory is to be taken from RADS/projects/lol_game_client/");
        return EXIT_FAILURE;
    }

    ItemManager::getInstance()->init();

    CORE_INFO("Game started");

	Game g;
	ENetAddress address;
	address.host = SERVER_HOST;
	address.port = SERVER_PORT;

    if (!g.initialize(&address, SERVER_KEY))
    {
        CORE_ERROR("Couldn't listen on port %d, or invalid key", SERVER_PORT);
        return EXIT_FAILURE;
    }

	g.netLoop();

    PathNode::DestroyTable(); // Cleanup

    return EXIT_SUCCESS;
}
