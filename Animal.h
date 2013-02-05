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

//! Define common attributes and behavior of cat and mouse agent 

class Animal: public Agent
{
protected:
	int energy; //! Energy affect how many movement animal can do
	int view;   //! The range that animal can see
	
public:
	//! Constructor member fuction
	Animal(string name, int energy, Agent *((& map)[MAP_W][MAP_L]), int view, int x, int y, void * agMng);

	//! Deconstructor member fuction
	virtual ~Animal();

	//! Moving towards a given position
	/*!
 	  \param x x coordinate 
	  \param y y coordinate
	  \return 0, if next position is the objective positon
	  \return -1, else 
	*/
	int  moveTowards(const int tx, const int ty);

	//! Calculating the direction of the objective
	/*!
 	  \param x x coordinate of objective
	  \param y y coordinate of objective
	  \param dir the direction calculated by this function
	*/
	void calcDir(const int tx, const int ty, Coordinate & dir);

	//! Finding next possible position for moving towards and calculate the probability distribution
	/*!
 	  \param dirCoor Moving direction
	  \param objCoor Coordinate of objective
	  \param posVec List of possible positions
	*/
	void findPossPositons(const Coordinate & dirCoor, 
			      const Coordinate & objCoor, 
			      vector <PosProb> & posVec);

	//! Adjust the probability of a possible position
	/*!
 	  \param posCoor Coordinate of the possible position
	  \param objCoor Coordinate of objective
	  \param posVec Push the possible possition and ajusted probability to this vector
	  \param prob Original probalibility
	  \param collProb Collective probability 
	*/
	void calcPosProb(const Coordinate & posCoor, 
			 const Coordinate & objCoor, 
			 vector <PosProb> & posVec, 
			 const float prob, 
			 const float collProb);

	//! According to the probability distribution, randomly generate a position
	/*!
	  \param posVec Probability distribution of possible next positions
 	  \param posCoor Coordinate of next position 
	*/
	void randPos(const vector <PosProb> & posVec, Coordinate & coord);

	//! Calculate the probability distribution and andomly choose an agent as objective 
	/*!
 	  \param agents Possible objective agent list 
	  \return Chosen agent
	*/
	Agent* choose(vector <Agent *> &agents);

	//! Randomly moving, each possible position has same probability
	void wander();

	//! Calculate view bound
	/*!
 	  \param ub up bound 
 	  \param db down bound 
 	  \param lb left bound 
 	  \param rb right bound 
	*/
	void getViewBound(int &ub, int &db, int &lb, int &rb);

	//! Finding the empty positon in animal's view
	/*!
 	  \param emps Empty position list 
	*/
	void getClosedEmpPoss(vector <Coordinate> &emps);
};



#endif
