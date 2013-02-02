#include <iostream>
#include <cstdio>
#include "Config.h"
#include "Mouse.h"
#include "Cat.h"
#include "Cheese.h"
#include "Obstacle.h"
#include "AgentManager.h"

void init();
void printMap(Agent *((& map)[MAP_W][MAP_L]));
void newMouse(int x, int y);
void newCat(int x, int y);
void newCheese(int x, int y);
void newObstacle(int x, int y);

Agent *((map)[MAP_W][MAP_L]);
AgentManager mousMng(map);
AgentManager catsMng(map);
AgentManager cheeMng(map);
AgentManager obstMng(map);

int main()
{
	char flag = '1';
	list <Agent *>::iterator itrt;

	// Initialize the map and create agents
	init();

	while(flag != 'q')
	{		
		// Print map
		printMap(map);

		// Tack action for each mouse
		list <Agent *>::iterator itrt;
		for(itrt = mousMng.agentList.begin();
			itrt != mousMng.agentList.end(); itrt++)
		{
			((Mouse *)(*itrt))->action();
		}

		// Tack action for each cat
		for(itrt = catsMng.agentList.begin();
			itrt != catsMng.agentList.end(); itrt++)
		{
			((Cat *)(*itrt))->action();
		}

		flag = getchar();	
	}
	
	mousMng.clearAgents();
	catsMng.clearAgents();
	cheeMng.clearAgents();
	obstMng.clearAgents();

	return 0;
}

// Initialize the map and create agents
void init()
{
	// Create cheese
	newCheese(2, 2);
	newCheese(3, 8);
	newCheese(6, 9);

	// Create Mouses
	newMouse(1, 1);
	newMouse(5, 5);
	newMouse(1, 1);
	newMouse(3, 5);
	newMouse(7, 7);
	newMouse(7, 9);
	
	// Create Cats
	newCat(8, 6);
	newCat(8, 0);

	// Create Obstacles 
	newObstacle(3, 0);
	newObstacle(3, 1);
	newObstacle(3, 2);
	newObstacle(3, 3);
	newObstacle(2, 3);
	newObstacle(0, 3);
}

// Create a mouse
void newMouse(int x, int y)
{
	new Mouse(map, x, y, (void *)&mousMng);
}

// Create a cat
void newCat(int x, int y)
{
	new Cat(map, x, y, (void *)&catsMng);
}

// Create a piece of cheese
void newCheese(int x, int y)
{
	new Cheese(map, x, y, (void *)&cheeMng);
}

// Create an obstacle
void newObstacle(int x, int y)
{
	new Obstacle(map, x, y, (void *)&obstMng);
}

// Print the map
void printMap(Agent *((& map)[MAP_W][MAP_L]))
{
	string name;

	for(int i = 0; i < MAP_W; i++)
	{
		for(int j = 0; j < MAP_L; j++)
		{
			if(map[i][j] == NULL)
			{
				cout << ". ";
			}
			else
			{
				if(map[i][j]->name.compare(MOUSE_NAME) == 0)
					cout << "M ";
				else if(map[i][j]->name.compare(CAT_NAME) == 0)
					cout << "C ";
				else if(map[i][j]->name.compare(CHEESE_NAME) == 0)
					cout << "F ";
				else if(map[i][j]->name.compare(OBSTACLE_NAME) == 0)
					cout << "O ";
			}
		}

		cout << endl;
	}

	cout << endl;
}
