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
	Mouse(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);
	virtual ~Mouse();

	void action();
	void scan(vector <Agent *> & ches, vector <Agent *> & cats);
};

#endif
