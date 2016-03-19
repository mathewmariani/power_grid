#pragma once

#include "base.h"
#include "CCardData.h"
#include "ISubject.h"

class CDeckData : public ISubject {
public:
	CDeckData();
	~CDeckData();

	void SetDeck(std::vector<CCardData> deck1, std::vector<CCardData> deck2, std::vector<CCardData> deck3, std::vector<CCardData> deck4);

	void PlayerBuysCard(int number);
	void FillInMarket();
	CCardData *FindCardInHold(int number);

	std::vector<CCardData> GetMarket();

	void Serialize(pugi::xml_node &parent);

private:
	std::vector<CCardData> m_vInDeck;
	std::vector<CCardData> m_vInMarket;
	std::vector<CCardData> m_vInHold;
	std::vector<CCardData> m_vDiscarded;

};