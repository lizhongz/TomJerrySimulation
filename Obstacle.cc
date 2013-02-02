#include "Obstacle.h"

Obstacle::Obstacle(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng): Agent(string(OBSTACLE_NAME), map, x, y, agMng)
{

}

Obstacle::~Obstacle()
{
	
}
