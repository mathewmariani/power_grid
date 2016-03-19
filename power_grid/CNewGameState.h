#pragma once

// Common
#include "IObserver.h"

#include "base.h"

class CMenuView : public IObserver {
public:
	CMenuView();
	~CMenuView();

	void SetData(CMenuData* pData);
	void Render();

	// IObserver
	void Update();

private:
	CMenuData* m_pModel;
};