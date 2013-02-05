#ifndef _OBSTACLE_H_
#define _OBSTACLE_H_

#include "Agent.h"
#include "Config.h"

using namespace std;

//! Obstacle agent
class Obstacle: public Agent
{
public:
	//! Constructor of Obstacle class
	/*!
	  \param map
	  \param x x coordinate value
	  \param y y coordinate value
	  \param agMng Corresponding agent manager
	*/
	Obstacle(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);

	//! Deconstructor of Obstacle class
	virtual ~Obstacle();
};

#endif
