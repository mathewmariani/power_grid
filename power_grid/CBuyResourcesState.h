#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "CGameData.h"

#include "base.h"

class CBuyResourcesState : public IState, ISubject {
public:
	CBuyResourcesState();
	~CBuyResourcesState();

	// IState
	void Start();
	void Enter();
	void Exit();
};