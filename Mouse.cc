#include <iostream>
#include <vector>
#include "Mouse.h"
#include "mt19937ar.h"

using namespace std;

Mouse::Mouse(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng)
	: Animal(string(MOUSE_NAME), MOUSE_ENERGY, map, MOUSE_VIEW, x, y, agMng) 
{

}

Mouse::~Mouse()
{

}

// Scan the envirioment and take action
void Mouse::action()
{
	vector <Agent *> ches;
	vector <Agent *> cats;

	// Look around
	scan(ches, cats);
	
	if(cats.size() != 0)
	{
		// If there are cats then run away
		wander();
	}
	else if(ches.size() != 0)
	{
		// If there are cheese

		// Choose a more closed piece of cheese 
		// with a high probability
		Cheese * che = (Cheese *)choose(ches);
		
		// Move towards the cheese
		if(moveTowards(che->coord.x, che->coord.y) == 0)
		{
			// move to cheese's position and eat the cheese
			map[coord.x][coord.y] = NULL;
			this->coord.x = che->coord.x;
			this->coord.y = che->coord.y;
			delete(che);
			map[coord.x][coord.y] = this;
		}
	}
	else
	{
		// If there is nothing then wander
		wander();
	}
}

// Look around and find cheese, cats and empty positions
void Mouse::scan(vector <Agent *> & ches, vector <Agent *> & cats)
{
	// View bounds
	int uBound;
	int dBound;
	int lBound;
	int rBound;
	
	// Calculate view bound in four direction 
	getViewBound(uBound, dBound, lBound, rBound);

	// Scan all the grids in the view of mouse
	for(int i = uBound; i <= dBound; i++)
	{
		for(int j = lBound; j <= rBound; j++)
		{
			if(map[i][j] != NULL)
			{
				if((map[i][j]->name).compare(CAT_NAME) == 0)
				{
					// If this position is a cat
					cats.push_back(map[i][j]);
				}
				else if((map[i][j]->name).compare(CHEESE_NAME) == 0)
				{
					// If this position is cheese 
					ches.push_back(map[i][j]);
				}
			}
		}
	}		
}



