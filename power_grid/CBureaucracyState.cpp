#include "CBureaucracyState.h"

CBureaucracyState::CBureaucracyState() {

}

CBureaucracyState::~CBureaucracyState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CBureaucracyState::Start() {
	std::cout << "Start Bureaucracy State.\n\n";

	for (int i = 0; i < pGameData->playerList.size(); i++) {
		if (pGameData->playerList[i].GetCard().size() == 0) {
			std::cout << "PLAYER " << pGameData->playerList[i].GetName() << " HAS NO POWER PLANTS!\n";
				continue;
		}
		std::cout << "It is player " << pGameData->playerList[i].GetName() << "'s turn to generate electricity.\n";
		std::cout << "You have " << pGameData->playerList[i].GetCard().size() << " card(s), choose one to excute:\n";
		for (int j = 0; j < pGameData->playerList[i].GetCard().size(); j++) {
			std::cout << j + 1 << ". CARD #" << pGameData->playerList[i].GetCard()[j]->GetNumber() << "\n";
		}
		std::cout << "0. EXIT\n";
		bool finish = false;
		int flag[3] = { 0, 0, 0 };
		do {
			int choice;
			std::cin >> choice;
			if (choice == 0) {
				finish = true;
			}
			else {
				if (flag[choice - 1] == 1) {
					std::cout << "ERROR: THIS PLANT HAS ALREADY POWERED!\n";
				}
				else {
					GenerateResults_e result = pGameData->playerList[i].GenerateElectricity(choice - 1);
					if (result == GENERATE_NOT_ENOUGH_FUEL)
						std::cout << "ERROR: NOT ENOUGH RESOURCES TO GENERATE ELETRICITY!\n";
					else {
						std::cout << "Power Plant #" << pGameData->playerList[i].GetCard()[choice - 1]->GetNumber() << " Power SUCCEEDED!\n";
						flag[choice - 1] = 1;
					}
				}
			}
		} while (finish == false);
		
		std::cout << "Player " << pGameData->playerList[i].GetName() << " got $" << pGameData->playerList[i].GetIncome() << " this turn.\n";

	
	}
//	m_pOwner->NextPhase();
}

void CBureaucracyState::Enter() {
	std::cout << "Entering Bureaucracy State\n";
}

void CBureaucracyState::Exit() {
	std::cout << "Exiting Bureaucracy State\n";
}