// Agent.h: interface for the Agent class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AGENT_H_
#define _AGENT_H_

#include <string>
#include "Coordinate.h"
#include "Config.h"

using namespace std;

class Agent  
{
public:
	string name;
	Coordinate coord;	// Coordinate
protected:
	Agent *((& map)[MAP_W][MAP_L]);	// Reference of map
	void * agentManager;
	

public:
	Agent(string name, Agent *((& map)[MAP_W][MAP_L]), int x, int y, void * agentManager);
	virtual ~Agent();
};

#endif
