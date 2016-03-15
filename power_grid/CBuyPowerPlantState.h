#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

class CBuyPowerPlantState : public IState, ISubject{
public:
	CBuyPowerPlantState();
	~CBuyPowerPlantState();

	// IState
	void Enter();
	void Exit();
};