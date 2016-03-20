#include "CCityView.h"

CCityView::CCityView() {

}
CCityView::~CCityView() {

}

void CCityView::SetData(CCityData* pData) {
	if (pData == nullptr) {
		return;
	}
	m_pModel = pData;
	m_pModel->Attach(this);
}

void CCityView::Update() {
	std::cout << "Name: " << m_pModel->GetName() << std::endl;
	std::cout << "Region: " << m_pModel->GetRegion() << std::endl;
	std::cout << " Neighbours: " << m_pModel->GetNeighbours() << std::endl;
	std::cout << " Number of Houses: " << m_pModel->GetHouses() << std::endl;
}

