// AgentManager.h: interface for the Agentmanager class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _AGENT_MANAGER_H_
#define _AGENT_MANAGER_H_

#include <list>
#include "Config.h"
#include "Agent.h"

using namespace std;

//! Maintain a agent list to manage agents
class AgentManager
{
private:
	//! Reference of map
	Agent *((& map)[MAP_W][MAP_L]);
public:
	//! Agent list
	list <Agent *> agentList;

	//! Constructor
	/*!
	  \param map 
	*/
	AgentManager(Agent *((& map)[MAP_W][MAP_L]));

	//! Deconstructor
	virtual ~AgentManager();

	//! Register a new agent
	/*!
	  \param agent new agent
	*/
	void agentRegister(Agent * agent);

	//! Deregister an agent
	/*!
	  \param agent the pointer of the agent
	*/
	void agentDeregister(Agent *agent);

	//! Clear all the agents in agent list
	void clearAgents();
};

#endif 
