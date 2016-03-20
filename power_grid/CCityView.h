#pragma once

// Model
#include "CCityData.h"

// Common
#include "IObserver.h"

#include "base.h"

class CCityView : public IObserver {
public:
	CCityView();
	~CCityView();

	void SetData(CCityData* pData);

	// IObserver
	void Update();

private:
	CCityData* m_pModel;
};