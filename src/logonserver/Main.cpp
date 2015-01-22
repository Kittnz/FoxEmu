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

#include <chrono>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <signal.h>
#include "Common.h"
#include "SystemConfig.h"

#define REFRESH_RATE 16666 // 60 fps

void Loop()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> tStart, tEnd;
    tStart = std::chrono::high_resolution_clock::now();
    long long tDiff;

    while(true)
    {
        tEnd = tStart;
        tStart = std::chrono::high_resolution_clock::now();
        tDiff = std::chrono::duration_cast<std::chrono::microseconds>(tStart - tEnd).count();

        tEnd = std::chrono::high_resolution_clock::now();

        if (tEnd - (std::chrono::microseconds(REFRESH_RATE)) < tStart)
            std::this_thread::sleep_for(std::chrono::microseconds(REFRESH_RATE)-(tEnd-tStart));

    }
}

int main(int argc, char ** argv)
{
    printf("\n         /\\   /\\                 _____         _____                 \n");
    printf("        // \\_// \\      ____     |  ___|____  _| ____|_ __ ___  _   _ \n");
    printf("        \\_     _/     /   /     | |_ / _ \\ \\/ /  _| | '_ ` _ \\| | | |\n");
    printf("         / * * \\     /^^^]      |  _| (_) >  <| |___| | | | | | |_| |\n");
    printf("         \\_\\O/_/     [   ]      |_|  \\___/_/\\_\\_____|_| |_| |_|\\__,_|\n");
    printf("          /   \\_     [   /\n");
    printf("          \\     \\_  /  /          League of Legends server emulator\n");
    printf("           [ [ /  \\/ _/        (c)2015 FoxEmu <http://www.foxemu.ovh/>\n");
    printf("          _[ [ \\  /_/                   Logon server daemon\n\n");

    printf("%s\n", _FULLVERSION);

    Loop();

    return EXIT_SUCCESS;
}
