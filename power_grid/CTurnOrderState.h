#pragma once

// Model
#include "CPlayerData.h"

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

// MAT: All the data is independant; this is a subject
class CTurnOrderState : public IState, ISubject {
public:
	CTurnOrderState();
	~CTurnOrderState();

	// IState
	void Enter();
	void Exit();
};