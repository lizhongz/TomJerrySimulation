#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Agent.h"
#include "Config.h"

using namespace std;

class Obstacle: public Agent
{
public:
	Obstacle(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);
	virtual ~Obstacle();
};

#endif
