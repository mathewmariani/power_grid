#pragma once

#include "CMenuView.h"
#include "CMenuData.h"

// Common
#include "IState.h"

#include "base.h"

class CMenuState : public IState {
public:
	CMenuState();
	~CMenuState();

	// IState
	void Enter();
	void Exit();

	void HandleInput();

private:
	CMenuView view;
	CMenuData data;
};