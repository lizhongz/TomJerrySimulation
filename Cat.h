#ifndef _CAT_H_
#define _CAT_H_

#include <vector>
#include "Animal.h"
#include "Config.h"

using namespace std;

//! Define the behaviors of cat agent
class Cat: public Animal
{
public:
	//! Constructor of cat class
	/*!
	  \param map
	  \param x x coordinate value
	  \param y y coordinate value
	  \param agMng Corresponding agent manager
	*/
	Cat(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);

	//! Deconstructor of cat class
	virtual ~Cat();

	//! Take action
	void action();

	//! Scan the environment
	void scan(vector <Agent *> & mouses);
};

#endif
