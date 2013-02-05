#ifndef _CHEESE_H_
#define _CHEESE_H_

#include "Agent.h"
#include "Config.h"

using namespace std;

//! Cheese Agent
class Cheese: public Agent
{
public:
	//! Constructor of Cheese class
	/*!
	  \param map
	  \param x x coordinate value
	  \param y y coordinate value
	  \param agMng Corresponding agent manager
	*/
	Cheese(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);

	//! Deconstructor of Cheese class
	virtual ~Cheese();
};

#endif
