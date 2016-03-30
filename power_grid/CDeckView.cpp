#include "CDeckView.h"

CDeckView::CDeckView() {

}

CDeckView::~CDeckView() {

}

void CDeckView::Initialize(CDeckData *pData) {
	if (pData == nullptr) {
		return;
	}

	m_pDeck = pData;
	m_pDeck->Attach(this);

	m_vPowerPlantMarket = m_pDeck->GetMarket();

	std::cout << "DeckView has been attached to the DeckData.\n";
}

void CDeckView::Update() {
	m_vPowerPlantMarket = m_pDeck->GetMarket();
	Print();
}

void CDeckView::Print() {
	std::cout << "Power plants market:\n";
	std::cout << "Reachable cards:\n";
	for (int i = 0; i < 4; i++)
		m_vPowerPlantMarket[i].Print();
	std::cout << "Unreachable cards:\n";
	for (int i = 4; i < 8; i++)
		m_vPowerPlantMarket[i].Print();
}