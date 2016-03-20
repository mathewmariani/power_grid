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

	std::cout << "DeckView has been attached to the DeckData.\n";
}

void CDeckView::Update(std::vector<CCardData> market) {
	m_vPowerPlantMarket = m_pDeck->GetMarket();
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