#pragma once

#include "base.h"
#include "CCardData.h"
#include "ISubject.h"

class CDeckData : public ISubject {
public:
	CDeckData();
	~CDeckData();

	void PlayerBuysCard(int number);
	void FillInMarket();

private:
	std::vector<CCardData> m_vInDeck;
	std::vector<CCardData> m_vInMarket;
	std::vector<CCardData> m_vInPlayer;
	std::vector<CCardData> m_vDiscarded;

};