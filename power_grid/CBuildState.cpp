#include "CBuildState.h"

CBuildState::CBuildState() {

}

CBuildState::~CBuildState() {
}

void CBuildState::Start() {
	std::cout << "Start Turn Order State\n";
//	m_pOwner->NextPhase();
}

void CBuildState::Enter() {
	std::cout << "Entering Building State\n";
}

void CBuildState::Exit() {
	std::cout << "Exiting Building State\n";
}