#pragma once
#pragma once

// Model
#include "CMapData.h"

// Common
#include "IObserver.h"

#include "base.h"

class CMapView : public IObserver {
public:
	CMapView();
	~CMapView();

	void Initialize(CMapData* pData);

	// IObserver
	void Update();

private:
	CMapData* m_pModel;
};