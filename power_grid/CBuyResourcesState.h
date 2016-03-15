#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

class CBuyResourcesState : public IState, ISubject {
public:
	CBuyResourcesState();
	~CBuyResourcesState();

	// IState
	void Enter();
	void Exit();
};