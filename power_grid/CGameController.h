//#pragma once
//
//// Common
//#include "StateMachine.h"
//
//#include "base.h"
//
//// MAT: Hold all the game data here
//class CGameController : StateMachine {
//public:
//	CGameController();
//	~CGameController();
//
//	void AddState(string name, IState* pState);
//	void LoadState(string name);
//	
//private:
//	std::unordered_map<string, IState*> m_States;
//};

#pragma once

// Common
#include "StateMachine.h"

#include "base.h"

// MAT: Hold all the game data here
class CGameController : StateMachine {
public:
	CGameController();
	~CGameController();

	void NextPhase();

private:
	vector<IState *> m_States;
	vector<IState *>::iterator m_Phase;
};