#pragma once

// Common
#include "CStateMachine.h"

#include "base.h"

// MAT: Hold all the game data here
class CGameController : CStateMachine {
public:
	CGameController();
	~CGameController();

	void NextPhase();

private:
	vector<IState *> m_States;
	vector<IState *>::iterator m_Phase;
};