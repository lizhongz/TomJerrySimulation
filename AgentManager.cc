#include <iostream>
#include "AgentManager.h"

using namespace std;

AgentManager::AgentManager(Agent *((& mp)[MAP_W][MAP_L])):map(mp)
{

}

AgentManager::~AgentManager()
{

}

// Agent register: add an agent to agent list
void AgentManager::agentRegister(Agent * pAgent)
{
	agentList.push_back(pAgent);
}

// Agent deregister: delete an agent from agent list
void AgentManager::agentDeregister(Agent *pAgent)
{
	agentList.remove(pAgent);
}

// Delete all the agents in agent list
void AgentManager::clearAgents()
{
	// Free all the agent in agent list
	list <Agent *>::iterator itrt;
	for(itrt = agentList.begin(); itrt != agentList.end(); )
	{
		delete(*itrt);
		itrt = agentList.begin();
	}
	
	// clear agent list
	agentList.clear();
}
