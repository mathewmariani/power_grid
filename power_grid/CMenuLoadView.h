#pragma once

// Model
#include "CMenuData.h"

// Common
#include "IObserver.h"

#include "base.h"

class CMenuLoadView : public IObserver {
public:
	CMenuLoadView();
	~CMenuLoadView();

	void Initialize(CMenuData* pData);

	// IObserver
	void Update();

private:
	CMenuData* m_pModel;
};