/*
 * Copyright (C) 2015 FoxEmu <http://www.foxemu.ovh/>
 * Copyright (C) 2012-2015 IntWars <http://leaguesandbox.com/>
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

#ifndef _AIMESH_H
#define _AIMESH_H
#include <vector>
#include <string>
#include "Target.h"
#include "Vector2.h"

#define MAX_TRIANGLE_COUNT (2<<15)
#define AIMESH_TEXTURE_SIZE 1024

struct ScanLine
{
    float x, y, z, u, v;
};

struct Vertex
{
    float x, y, z;
};

#pragma pack(push, 1)
struct Triangle
{
    struct
    {
        float v1[3]; // Seems to be a vertex [x,y,z]
        float v2[3]; // Seems to be a vertex [x,y,z]
        float v3[3]; // Seems to be a vertex [x,y,z]
    } Face; // If above is true

    short unk1;
    short unk2;
    short triangle_reference;
};

struct __AIMESHFILE
{
    char magic[8];
    int version;
    int triangle_count;
    int zero[2];

    Triangle triangles[MAX_TRIANGLE_COUNT];
    // TODO: I have to find a better way to do this. :/
    // Basically, it's a set of triangles that go on for triangle_count.
    // Dynamic allocation is stupid, and this way is potentially well, unsafe.
    // pointers will make the app think that the first 4 bytes are a pointer.. Sigh.
};
#pragma pack(pop)

class Object;
class AIMesh
{
    public:
        AIMesh();
        ~AIMesh();

        bool load(std::string inputFile);

        float getY(float argX, float argY);
        bool isWalkable(float argX, float argY) { return getY(argX, argY) > -254.0f; }
        float castRay(Vector2 origin, Vector2 destination, bool inverseRay = false) { return sqrt(castRaySqr(origin, destination, inverseRay)); }
        float castRaySqr(Vector2 origin, Vector2 destination, bool inverseRay = false);
        float castInfiniteRaySqr(Vector2 origin, Vector2 direction, bool inverseRay = false);
        float castInfiniteRay(Vector2 origin, Vector2 direction, bool inverseRay = false) { return sqrt(castInfiniteRaySqr(origin, direction, inverseRay)); }
        bool isAnythingBetween(Vector2 a, Vector2 b);
        bool isAnythingBetween(Object* a, Object* b);
        Vector2 getClosestTerrainExit(Object* a, Vector2 location, bool noForward = true);

        float getWidth() { return mapWidth; }
        float getHeight() { return mapHeight; }
        float getSize() { return (mapHeight > mapWidth)? mapHeight : mapWidth; }

        Vector2 TranslateToTextureCoordinate(Vector2 vector);
        Vector2 TranslateToRealCoordinate(Vector2 vector);

        bool isLoaded() { return loaded; }

    private:
        void drawLine(float x1, float y1, float x2, float y2, char *heightInfo, unsigned width, unsigned height);
        void drawTriangle(Triangle triangle, unsigned width, unsigned height);
        void fillScanLine(Vertex vertex1, Vertex vertex2);
        bool outputMesh(unsigned width, unsigned height);
        bool writeFile(unsigned width, unsigned height);


        std::vector<unsigned char> buffer;
        __AIMESHFILE *fileStream;

        double lowX, lowY, highX, highY, lowestZ;
        ScanLine scanlineLowest[AIMESH_TEXTURE_SIZE], scanlineHighest[AIMESH_TEXTURE_SIZE];
        float *heightMap; float *xMap; float *yMap;
        float mapWidth, mapHeight;
        bool loaded;
};

#endif
