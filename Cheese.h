#ifndef _CHEESE_H_
#define _CHEESE_H_

#include "Agent.h"
#include "Config.h"

using namespace std;

class Cheese: public Agent
{
public:
	Cheese(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);
	virtual ~Cheese();
};

#endif
