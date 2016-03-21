#pragma once

// Common
#include "IState.h"

#include "base.h"

class CGameState : public IState {
public:
	CGameState();
	~CGameState();

	// IState
	void Start();
	void Enter();
	void Exit();

	void HandleInput();
};