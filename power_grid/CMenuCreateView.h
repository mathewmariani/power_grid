#pragma once

// Model
#include "CMenuData.h"

// Common
#include "IObserver.h"

#include "base.h"

class CMenuCreateView : public IObserver {
public:
	CMenuCreateView();
	~CMenuCreateView();

	void Initialize(CMenuData* pData);

	// IObserver
	void Update();

private:
	CMenuData* m_pModel;
};