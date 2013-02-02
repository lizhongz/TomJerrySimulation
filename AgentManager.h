// AgentManager.h: interface for the Agentmanager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AGENT_MANAGER_H_
#define _AGENT_MANAGER_H_

#include <list>
#include "Config.h"
#include "Agent.h"

using namespace std;

class AgentManager
{
private:
	Agent *((& map)[MAP_W][MAP_L]);	// Reference of map
public:
	list <Agent *> agentList; // Agent list

	AgentManager(Agent *((& map)[MAP_W][MAP_L]));
	virtual ~AgentManager();
	void agentRegister(Agent * agent);
	void agentDeregister(Agent *agent);
	void clearAgents();
};

#endif 
