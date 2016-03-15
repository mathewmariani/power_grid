#include "CMenuLoadView.h"

CMenuLoadView::CMenuLoadView() {

}

CMenuLoadView::~CMenuLoadView() {

}

void CMenuLoadView::Initialize(CMenuData* pData) {
	if (pData == nullptr) {
		return;
	}

	m_pModel = pData;
	m_pModel->Attach(this);

	std::cout << "Welcome to Power Grid!\n\n";
	std::cout << "Select an option.\n";

	for (int i = 0; i < m_pModel->GetMenuOptions().size(); i++) {
		std::cout << i + 1 << ".\t" << m_pModel->GetMenuOptions()[i] << std::endl;
	}
}


// IObserver
void CMenuLoadView::Update() {

}