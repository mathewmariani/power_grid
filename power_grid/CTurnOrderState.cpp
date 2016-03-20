#include "CTurnOrderState.h"
#include "CGameController.h"
class CGameController;

CTurnOrderState::CTurnOrderState() {

}

CTurnOrderState::~CTurnOrderState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CTurnOrderState::Start() {
	std::cout << "Start Turn Order State\n";
	m_pOwner->NextPhase();
}

void CTurnOrderState::Enter() {
	std::cout << "Entering Turn Order State\n";
}

void CTurnOrderState::Exit() {
	std::cout << "Exiting Turn Order State\n";
}
