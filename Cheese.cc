#include "Cheese.h"

Cheese::Cheese(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng): Agent(string(CHEESE_NAME), map, x, y, agMng)
{

}

Cheese::~Cheese()
{
	
}
