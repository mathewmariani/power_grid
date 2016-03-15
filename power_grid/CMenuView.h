#pragma once

// Model
#include "CMenuData.h"

// Common
#include "IObserver.h"

#include "base.h"

class CMenuView : public IObserver {
public:
	CMenuView();
	~CMenuView();

	void Initialize(CMenuData* pData);

	// IObserver
	void Update();

private:
	CMenuData* m_pModel;
};