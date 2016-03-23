#include "CMarketView.h"

CMarketView::CMarketView() {

}

CMarketView::~CMarketView() {

}

void CMarketView::SetData(CMarket* pData) {
	if (pData == nullptr) {
		return;
	}

	m_pData = pData;
	m_pData->Attach(this);
	std::cout << m_pData;
}

void CMarketView::Render() {
	std::cout << "Welcome to the Resource Market!\n\n";

	std::cout << "Item\t\tStock\t\tPrice" << std::endl;
	std::cout << "COAL\t\t" << m_pData->GetCoal() << "\t\t" << m_pData->GetCostOfCoal() << std::endl;
	std::cout << "OIL\t\t" << m_pData->GetOil() << "\t\t" << m_pData->GetCostOfOil() << std::endl;
	std::cout << "GARBAGE\t\t" << m_pData->GetGarbage() << "\t\t" << m_pData->GetCostOfGarbage() << std::endl;
	std::cout << "URANIUM\t\t" << m_pData->GetUranium() << "\t\t" << m_pData->GetCostOfUranium() << std::endl;
}


// IObserver
void CMarketView::Update() {
	Render();
}