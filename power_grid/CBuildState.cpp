#include "CBuildState.h"

CBuildState::CBuildState() {

}

CBuildState::~CBuildState() {
}

void CBuildState::Start() {
	std::cout << "Start Building State\n";

	for (int i = (int)pGameData->playerList.size(); i >= 0; i--) {
		std::cout << "It is player " << pGameData->playerList[i].GetName() << "'s turn to build.\n";
	}
//	m_pOwner->NextPhase();
}

void CBuildState::Enter() {
	std::cout << "Entering Building State\n";
}

void CBuildState::Exit() {
	std::cout << "Exiting Building State\n";
}