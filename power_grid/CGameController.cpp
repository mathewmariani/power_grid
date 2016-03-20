// Controller
//#include "CGameController.h"
//
//CGameController::CGameController() {
//
//}
//
//CGameController::~CGameController() {
//	for (auto it = m_States.begin(); it != m_States.end(); ++it) {
//		delete (it->second);
//	}
//}
//
//void CGameController::AddState(string name, IState* pState) {
//	pState->Initialize(this);
//	m_States.insert({ name, pState });
//}
//
//void CGameController::LoadState(string name) {
//	auto pState = m_States.find(name);
//
//	if (pState == m_States.end()) {
//		std::cout << "!!! ERROR: State not found" << std::endl;
//	} else {
//		ChangeState(pState->second);
//	}
//}

// Controller
#include "CGameController.h"

// States
#include "CTurnOrderState.h"
#include "CBuyPowerPlantState.h"
#include "CBuyResourcesState.h"
#include "CBuildState.h"
#include "CBureaucracyState.h"

// Model
#include "CGameData.h"

CGameController::CGameController() {
	m_States.push_back(new CTurnOrderState);
	m_States.push_back(new CBuyPowerPlantState);
	m_States.push_back(new CBuyResourcesState);
	m_States.push_back(new CBuildState);
	m_States.push_back(new CBureaucracyState);

	for (auto it = m_States.begin(); it != m_States.end(); it++) {
		(*it)->Initialize(this);
	}

	m_Phase = m_States.begin();
	ChangeState(*m_Phase);
}

CGameController::~CGameController() {
	while (!m_States.empty()) {
		delete m_States.back();
		m_States.pop_back();
	}
}

void CGameController::NextPhase() {
	// MAT: I dont like it, but runtime seems to like it
	if (m_Phase != m_States.end()) {
		m_Phase++;

		if (m_Phase == m_States.end()) {
			std::cout << "That's a complete round!\n\n";
			m_Phase = m_States.begin();
			pGameData->currentRound++;
		}

		ChangeState(*m_Phase);
	}
}