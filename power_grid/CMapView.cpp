#include "CMapView.h"

CMapView::CMapView() {}
CMapView::~CMapView() {}

void CMapView::Initialize(CMapData* pData) {
	if (pData == nullptr) {
		return;
	}

	m_pModel = pData;
	m_pModel->Attach(this);
}

void CMapView::Update() {
	std::cout << "This is the current list of cities on the map" << std::endl;
	m_pModel->DisplayCities();
}
