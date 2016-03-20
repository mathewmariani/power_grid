#pragma once

#include "CMenuView.h"
#include "CMenuData.h"


// Common
#include "IState.h"

#include "base.h"

class CInitializeState : public IState {
public:
	CInitializeState();
	~CInitializeState();

	// IState
	void Enter();
	void Exit();

	void HandleInput();

private:
	CMenuView view;
	CMenuData data;
};