#pragma once

#include "IObserver.h"
#include "CCardData.h"
#include "CDeckData.h"
#include "base.h"


class CDeckView : public IObserver {
public:
	CDeckView();
	~CDeckView();

	void Initialize(CDeckData *pData);

	void Update(std::vector<CCardData> market);

	void Print();
private:
	std::vector<CCardData> m_vPowerPlantMarket;
	CDeckData* m_pDeck;
};