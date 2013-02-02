#include <iostream>
#include "Cat.h"
#include "Mouse.h"
#include "Config.h"

using namespace std;


Cat::Cat(Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agMng)
	: Animal(string(CAT_NAME), CAT_ENERGY, map, CAT_VIEW, x, y, agMng) 
{

}

Cat::~Cat()
{

}

void Cat::action()
{
	vector <Agent *> mouses;

	// Look around
	scan(mouses);

	if(mouses.size() != 0)
	{
		// If there are mouses 
		
		// Choose a more closed mouse
		// with a high probability
		Mouse * mou = (Mouse *)choose(mouses);

		// Move towards the mouse 
		if(moveTowards(mou->coord.x, mou->coord.y) == 0)
		{
			// If next position is mouse's position
			// then move to mouse's position and eat the mouse 
			map[coord.x][coord.y] = NULL;
			this->coord.x = mou->coord.x;
			this->coord.y = mou->coord.y;
			delete(mou);
			map[coord.x][coord.y] = this;
		}
	}
	else
	{
		// If there is nothing then wander
		wander();
	}
}

void Cat::scan(vector <Agent *> & mouses)
{
	// View bounds
	int uBound;
	int dBound;
	int lBound;
	int rBound;
	
	// Calculate view bound in four direction 
	getViewBound(uBound, dBound, lBound, rBound);

	// Scan all the grids in the view of cat 
	for(int i = uBound; i <= dBound; i++)
	{
		for(int j = lBound; j <= rBound; j++)
		{
			if((map[i][j] != NULL) 
				&& ((map[i][j]->name).compare(MOUSE_NAME) == 0))
			{
				mouses.push_back(map[i][j]);
			}
		}
	}
}


