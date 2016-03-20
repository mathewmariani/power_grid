#pragma once

// Common
#include "IState.h"
#include "ISubject.h"

#include "base.h"

class CBuildState : public IState, ISubject {
public:
	CBuildState();
	~CBuildState();

	// IState
	void Start();
	void Enter();
	void Exit();
};