#pragma once

// Common
#include "StateMachine.h"
#include "IState.h"
#include "ISubject.h"

#include "CGameData.h"

#include "base.h"

class CBuyPowerPlantState : public IState, ISubject{
public:
	CBuyPowerPlantState();
	~CBuyPowerPlantState();

	// IState
	void Start();
	void Enter();
	void Exit();
};