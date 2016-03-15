#pragma once

// Data
#include "CPlayerData.h"

// Common
#include "IObserver.h"

// Model
#include "CMenuData.h"

// View
#include "CMenuView.h"

#include "base.h"


// MAT: This should probably be a StateMachine
// but im still working on the menu
class CMenuController : public IObserver {
public:
	CMenuController();
	~CMenuController();

	// IObserver
	void Update();

private:
	CMenuData m_MenuData;
	CMenuView m_MenuView;
};