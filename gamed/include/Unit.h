#ifndef _UNIT_H
#define _UNIT_H

#include "Object.h"
#include "Stats.h"

class AI;

class Unit : public Object {

protected:
   Stats* stats;
   AI* ai;

public:
   Unit(Map* map, uint32 id, Stats* stats, float x = 0, float y = 0, AI* ai = 0) : Object(map, id, x, y, 0, 0), stats(stats), ai(ai) { }
   virtual ~Unit();
   Stats& getStats() { return *stats; }
   virtual void update(unsigned int diff);

};

#endif