#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

class CGameState : public IState, public ISubject {
public:
	CGameState();
	~CGameState();

	// IState
	void Start();
	void Enter();
	void Exit();

	void HandleInput();
};