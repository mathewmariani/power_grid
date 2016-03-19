#pragma once

// Common
#include "IState.h"

#include "base.h"

// MAT: Hold all the game data here
class CGameController {
public:
	CGameController();
	~CGameController();

	void AddState(string name, IState* pState);
	void ChangeState(string name);

	IState* GetCurrentState();
	const IState* GetCurrentState() const;

private:
	void Transition(IState* pState);
	
private:
	std::unordered_map<string, IState*> m_States;
	IState* m_pCurrentState;
	bool m_bInTransition;
};