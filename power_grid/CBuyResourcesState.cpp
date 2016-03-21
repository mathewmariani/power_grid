#include "CBuyResourcesState.h"

CBuyResourcesState::CBuyResourcesState() {

}

CBuyResourcesState::~CBuyResourcesState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CBuyResourcesState::Start() {
	std::cout << "Start Turn Order State\n";
	
	for (int i = pGameData->playerList.size() - 1; i >= 0; i--) {
		std::cout << "It is player " << pGameData->playerList[i].GetName() << "'s turn to buy resources.\n";

	}
//	m_pOwner->NextPhase();
}

void CBuyResourcesState::Enter() {
	std::cout << "Entering Buy Resources State\n";
}

void CBuyResourcesState::Exit() {
	std::cout << "Exiting Buy Resources State\n";
}