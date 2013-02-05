// Animal.cpp: implementation of the Animal class.
//
//////////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <cmath>
#include "Animal.h"
#include "mt19937ar.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Animal::Animal(string name, int energy, 
		Agent *((& map)[MAP_W][MAP_L]), int view, int x, int y, void * agMng)
		: Agent(name, map, x, y, agMng)
{
	this->energy	= energy;
	this->view	= view;
}

Animal::~Animal()
{
	
}

// Animal moves towards a given direction
// If animal will arive at objective position
// return 0
// else return -1
int Animal::moveTowards(const int tx, const int ty)
{
	int			tmpEng = energy;
	Coordinate	dirCoor;
	Coordinate	objCoor(tx, ty);
	Coordinate	coordTmp;

	// Calculate the direction of objective
	calcDir(tx, ty, dirCoor);
	
	while(tmpEng != 0)
	{
		// next possible positions' vector
		vector <PosProb> posVec;

		// Find possible positions for animal to move to
		findPossPositons(dirCoor, objCoor, posVec);

		// Decide next positon randomly
		randPos(posVec, coordTmp);

		tmpEng -= 1;

		// If next position is objective positon
		if(coordTmp.x == objCoor.x && coordTmp.y == objCoor.y)
			return 0;

		// Go to next postion
		map[coord.x][coord.y] = NULL;
		coord.x = coordTmp.x;
		coord.y = coordTmp.y;
		map[coord.x][coord.y] = this;
	}

	return -1;
}

// According to the probability distribution to randomly get a position
void Animal::randPos(const vector <PosProb> & posVec, Coordinate & coord)
{
	float rnd;
	rnd = genrand_real1();

	for(int i = 0; i < posVec.size(); i++)
	{
		if(rnd <= posVec[i].prob)
		{
			coord.x = posVec[i].x;
			coord.y = posVec[i].y;

			return;
		}
	}
}

// Calculate the direction of objective
void Animal::calcDir(const int tx, const int ty, Coordinate & dir)
{
	int dx = tx - this->coord.x;
	int dy = ty - this->coord.y;

	if(dx >= 1)
		dir.x = 1;
	else if (dx == 0)
		dir.x = 0;
	else
		dir.x = -1;

	if(dy >= 1)
		dir.y = 1;
	else if (dy == 0)
		dir.y = 0;
	else
		dir.y = -1;
}

// Find possible positions for animal to move to
void Animal::findPossPositons(const Coordinate & dirCoor, const Coordinate & objCoor, 
						 vector <PosProb> & posVec)
{
	float		collProb = 0;	// Collective probability
	float		prob;
	Coordinate	posCoor;
	
	if((dirCoor.x != 0) && (dirCoor.y != 0))
	{
		// If objective position is not in a harizontal or vertical direction

		// Find possible positions and calculate their probability
		// from positive position to negative position

		prob = S1_POS_PROB_A;
		collProb += prob;
		posCoor.x = this->coord.x + dirCoor.x;
		posCoor.y = this->coord.y;
		calcPosProb(posCoor, objCoor, posVec, prob, collProb);

		prob = S1_POS_PROB_B;
		collProb += prob;
		posCoor.x = this->coord.x;
		posCoor.y = this->coord.y + dirCoor.y;
		calcPosProb(posCoor, objCoor, posVec, prob, collProb);
		
		prob = S1_POS_PROB_C;
		collProb += prob;
		posCoor.x = this->coord.x;
		posCoor.y = this->coord.y;
		calcPosProb(posCoor, objCoor, posVec, prob, collProb);

		prob = S1_POS_PROB_D;
		collProb += prob;
		posCoor.x = this->coord.x - dirCoor.x;
		posCoor.y = this->coord.y;
		calcPosProb(posCoor, objCoor, posVec, prob, collProb);

		prob = S1_POS_PROB_E;
		collProb += prob;
		posCoor.x = this->coord.x;
		posCoor.y = this->coord.y - dirCoor.y;
		calcPosProb(posCoor, objCoor, posVec, prob, collProb);
	}
	else
	{
		if(dirCoor.x != 0)
		{
			prob = S2_POS_PROB_A;
			collProb += prob;
			posCoor.x = this->coord.x + dirCoor.x;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_B;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_C;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y + 1;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_D;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y - 1;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_E;
			collProb += prob;
			posCoor.x = this->coord.x - dirCoor.x;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);
		}
		else if(dirCoor.y != 0)
		{
			prob = S2_POS_PROB_A;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y + dirCoor.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_B;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_C;
			collProb += prob;
			posCoor.x = this->coord.x + 1;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_D;
			collProb += prob;
			posCoor.x = this->coord.x - 1;
			posCoor.y = this->coord.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);

			prob = S2_POS_PROB_E;
			collProb += prob;
			posCoor.x = this->coord.x;
			posCoor.y = this->coord.y - dirCoor.y;
			calcPosProb(posCoor, objCoor, posVec, prob, collProb);
		}
	}
}

//! Adjust the probability of a possible position
void Animal::calcPosProb(const Coordinate & posCoor, const Coordinate & objCoor, 
						 vector <PosProb> & posVec, const float prob, const float collProb)
{
	PosProb	posProb;
	
	if( (posCoor.x >= 0 && posCoor.x < MAP_W)
		&& (posCoor.y >= 0 && posCoor.y < MAP_L)
		&& ((map[posCoor.x][posCoor.y] == NULL)
			|| (posCoor.x == coord.x 
				&& posCoor.y == coord.y)
			|| (posCoor.x == objCoor.x 
				&& posCoor.y == objCoor.y)) )
	{
		// Following conditions are needed:
		// 1. The coordinate of given position must in the map
		// 2. The position should be empty 
		//    or is its onw position 
		//    or this positon is the objective positon

		// Add this postion to possible position vector
		posProb.x = posCoor.x;
		posProb.y = posCoor.y;
		posProb.prob = collProb;
		posVec.push_back(posProb);
	}
	else
	{
		// This position is not empty and is not objective postion
		// and will not be insert to possible position vector

		if(posVec.size() != 0)
		{
			// Allocate this position's probability 
			// to previous more possible on average

			float avgProb = prob / posVec.size();

			vector <PosProb>::iterator itrt;
			for(itrt = posVec.begin(); itrt != posVec.end(); itrt++)
			{
				itrt->prob += avgProb;
				avgProb += avgProb;
			}
		}
	}
}

// Randomly choose an agent as objective from an agent list 
Agent* Animal::choose(vector <Agent *> &agents)
{
	// Distances from this animal to other agents
	vector <int>	dsts; 
	// choosed probability distribution
	vector <float>	probDistr; 

	float	sum; 	
	int	dst;
	float	prob;

	// Calculate the distances to other agents
	sum = 0;	
	for(int i = 0; i < agents.size(); i++)
	{
		dst = abs(agents[i]->coord.x - this->coord.x)
			+ abs(agents[i]->coord.y - this->coord.y);	
		dsts.push_back(dst);
		sum += (1.0 / dst);
	}

	// Calculate choosed probability distribution
	prob = 0;
	for(int i = 0; i < dsts.size(); i++)
	{
		prob +=  ((1.0 / dsts[i]) / sum);
		probDistr.push_back(prob);
	}

	// Choose an agent according to the probability distribution
	float rnd = genrand_real1();
	for(int i = 0; i < probDistr.size(); i++)
	{
		if(rnd <= probDistr[i])
			return agents[i];
	}

	return NULL;
}

// Randomly moving
void Animal::wander()
{
	vector <Coordinate> emps;
	int tmpEng = this->energy;	
	int rndPosInx;
	int x;
	int y;

	while(tmpEng != 0)
	{
		// Get closed empty positions
		getClosedEmpPoss(emps);

		// Randomly choose a position with equal probability
		rndPosInx = (int)(emps.size() * genrand_real1());
		x = emps[rndPosInx].x;
		y = emps[rndPosInx].y;

		// move to the new position 
		map[coord.x][coord.y] = NULL;
		this->coord.x = x;
		this->coord.y = y;
		map[x][y] = this;

		tmpEng -= 1;
	}
}

// Calculate the view bound in four direction: up, down, left, right
void Animal::getViewBound(int &ub, int &db, int &lb, int &rb)
{
	// View bounds
	ub = coord.x - view;
	db = coord.x + view;
	lb = coord.y - view;
	rb = coord.y + view;
	
	// The coordinates must in the map
	if(ub < 0)
		ub = 0;
	if(db >= MAP_W)
		db = MAP_W - 1;
	if(lb < 0)
		lb = 0;
	if(rb >= MAP_L)
		rb = MAP_L - 1;
}

// Get closed empty positions
void Animal::getClosedEmpPoss(vector <Coordinate> &emps)
{
	if((coord.x - 1 >= 0) && map[coord.x - 1][coord.y] == NULL)
		emps.push_back(Coordinate(coord.x - 1, coord.y));
	if((coord.x + 1 < MAP_W) && map[coord.x + 1][coord.y] == NULL)
		emps.push_back(Coordinate(coord.x + 1, coord.y));
	if((coord.y - 1 >= 0) && map[coord.x][coord.y - 1] == NULL)
		emps.push_back(Coordinate(coord.x, coord.y - 1));
	if((coord.y + 1 < MAP_L) && map[coord.x][coord.y + 1] == NULL)
		emps.push_back(Coordinate(coord.x, coord.y + 1));
	emps.push_back(coord);
}
