// Controller
#include "CGameController.h"

CGameController::CGameController() {

}

CGameController::~CGameController() {
	for (auto it = m_States.begin(); it != m_States.end(); ++it) {
		delete (it->second);
	}
}

void CGameController::AddState(string name, IState* pState) {
	pState->Initialize(this);
	m_States.insert({ name, pState });
}

void CGameController::ChangeState(string name) {
	auto pState = m_States.find(name);

	if (pState == m_States.end()) {
		std::cout << "!!! ERROR: State not found" << std::endl;
	} else {
		Transition(pState->second);
	}
}

IState* CGameController::GetCurrentState() {
	return m_pCurrentState;
}

const IState* CGameController::GetCurrentState() const {
	return m_pCurrentState;
}

void CGameController::Transition(IState* pState) {
	if (pState == nullptr) {
		return;
	}

	if (m_pCurrentState == pState || m_bInTransition) {
		return;
	}

	m_bInTransition = true;

	if (m_pCurrentState != nullptr) {
		m_pCurrentState->Exit();
	}

	m_pCurrentState = pState;
	m_pCurrentState->Enter();

	m_bInTransition = false;
}