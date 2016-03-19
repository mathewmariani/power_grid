#include "CMapView.h"

CMapView::CMapView()	{}
CMapView::~CMapView()	{}

void CMapView::Initialize(CMapData* pData) {
	if (pData == nullptr) {
		return;
	}

	m_pModel = pData;
	m_pModel->Attach(this);
}

void CMapView::Update() {

}

