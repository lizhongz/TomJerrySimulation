// Agent.h: interface for the Agent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AGENT_H_
#define _AGENT_H_

#include <string>
#include "Coordinate.h"
#include "Config.h"

using namespace std;

//! Define the name and coordinate of an agent
/*! 
 * An entity during simulation 
 */

class Agent  
{
public:
	string name;		//!< Agent name
	Coordinate coord;	//!< Coordinate of agent in a map
protected:
	Agent *((& map)[MAP_W][MAP_L]);	//!< Reference of map
	void * agentManager;		//!< Corresponding agent manager

public:
	//! Constructor of Agent class
	/*!
 	  \param name agent name
	  \param map
	  \param x x coordinate value
	  \param y y coordinate value
	  \param agentManager Corresponding agent manager
	*/
	Agent(string name, Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agentManager);

	//! Deconstructor of Agent class
	virtual ~Agent();
};

#endif
