#pragma once

// Model
#include "CMarket.h"

// Common
#include "IObserver.h"

#include "base.h"

class CMarketView : public IObserver {
public:
	CMarketView();
	~CMarketView();

	void SetData(CMarket* pData);
	void Render();

	// IObserver
	void Update();

private:
	CMarket* m_pData;
};