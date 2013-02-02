// Agent.cpp: implementation of the Agent class.
//
//////////////////////////////////////////////////////////////////////

#include "Agent.h"
#include "AgentManager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Agent::Agent(string nm, Agent *((& m)[MAP_W][MAP_L]), int x, int y, void * mng) : name(nm), map(m), coord(x, y), agentManager(mng)
{
	map[x][y] = this;
	
	((AgentManager *)agentManager)->agentRegister(this);
}

Agent::~Agent()
{
	map[coord.x][coord.y] = NULL;

	((AgentManager *)agentManager)->agentDeregister(this);
}

