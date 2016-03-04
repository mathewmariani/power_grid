#pragma once

#include "base.h"
#include "CCard.h"

class CDeck {
public:
	CDeck();
	~CDeck();

	CCard Draw();
	CCard FindCard(int number);

private:
	std::vector<CCard> m_vDeck;
	int m_iCurrentCard;
};
