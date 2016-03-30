#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "CGameData.h"

#include "base.h"

class CBureaucracyState : public IState, ISubject {
public:
	CBureaucracyState();
	~CBureaucracyState();

	// IState
	void Start();
	void Enter();
	void Exit();
};