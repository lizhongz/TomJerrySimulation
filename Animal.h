// Animal.h: interface for the Animal class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <vector>
#include "Agent.h"
#include "Coordinate.h"
#include "Config.h"

using namespace std;

// Probability that animal will go a position.
// From positive position to negative position
#define S1_POS_PROB_A	0.45
#define S1_POS_PROB_B	0.45
#define S1_POS_PROB_C	0.05
#define S1_POS_PROB_D	0.025
#define S1_POS_PROB_E	0.025
#define S2_POS_PROB_A	0.8
#define S2_POS_PROB_B	0.1
#define S2_POS_PROB_C	0.04
#define S2_POS_PROB_D	0.04
#define S2_POS_PROB_E	0.02


// Probability that animal will go to a position
typedef struct
{
	int		x;
	int		y;
	float	prob;
}PosProb;

class Animal: public Agent
{
protected:
	int energy;		// Energy affect how many movement animal can do
	int view;		// The range that animal can see
	
public:
	Animal(string name, int energy, 
		Agent *((& map)[MAP_W][MAP_L]), int view, int x, int y, void * agMng);

	virtual ~Animal();

	int  moveTowards(const int tx, const int ty);
	void calcDir(const int tx, const int ty, Coordinate & dir);
	void findPossPositons(const Coordinate & dirCoor, 
						  const Coordinate & objCoor, 
						  vector <PosProb> & posVec);
	void calcPosProb(const Coordinate & posCoor, 
					 const Coordinate & objCoor, 
					 vector <PosProb> & posVec, 
					 const float prob, 
					 const float collProb);
	void randPos(const vector <PosProb> & posVec, Coordinate & coord);
	Agent* choose(vector <Agent *> &agents);
	void wander();
	void getViewBound(int &ub, int &db, int &lb, int &rb);
	void getClosedEmpPoss(vector <Coordinate> &emps);

};



#endif
