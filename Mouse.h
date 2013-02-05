#ifndef _MOUSE_H_
#define _MOUSE_H_

#include <vector>
#include "Animal.h"
#include "Config.h"
#include "Cat.h"
#include "Cheese.h"

using namespace std;

//! Define the behaviors of mouse agent

class Mouse: public Animal
{
public:
	//! Constructor of Mouse class
	/*!
	  \param map
	  \param x x coordinate value
	  \param y y coordinate value
	  \param agMng Corresponding agent manager
	*/
	Mouse(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);

	//! Deconstructor of mouse class
	virtual ~Mouse();

	//! Take action
	void action();

	//! Scan the environment
	void scan(vector <Agent *> & ches, vector <Agent *> & cats);
};

#endif
