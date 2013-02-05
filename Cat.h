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
	Cat(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng);
	virtual ~Cat();

	void action();
	void scan(vector <Agent *> & mouses);
};

#endif
