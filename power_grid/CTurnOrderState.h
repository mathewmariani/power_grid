#pragma once

// Model
#include "CPlayerData.h"
#include "CGameData.h"

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

// MAT: All the data is independent; this is a subject
class CTurnOrderState : public IState, ISubject {
public:
	CTurnOrderState();
	~CTurnOrderState();

	// IState
	void Enter();
	void Exit();
};

bool CompareFunction(const CPlayerData &p1, const CPlayerData &p2);