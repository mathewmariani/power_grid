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
		m_View.Render();

		std::cout << std::endl;
		std::cout << "0: EXIT" << std::endl;
		std::cout << "1: COAL" << std::endl;
		std::cout << "2: OIL" << std::endl;
		std::cout << "3: GARBAGE" << std::endl;
		std::cout << "4: URANIUM" << std::endl;

		BuyResults_e result;
		bool finish = false;

		do {
			int choice;
			std::cin >> choice;

			if (choice == 0)
				finish = true;

			result = pGameData->PlayerAttemptsToBuyResource(i, choice);

		} while (finish == false);
		//Junan: Here for the loop-ending condition, it is not perfect. The real auto-quit situation should be any of these:
		//       1. When a player cannot afford even the cheapest resource
		//       2. When the whole market is sold out
		//       3. When a player quits manually
		//       I only implemented the 3rd one, for convenience
		//       But I think it's good, for demo, and even for playing. Because if 1 or 2 situation occurs, players still 
		//       won't be able to do any purchases, only they have to quit manually by pressing '0'.
	}
//	m_pOwner->NextPhase();
}

void CBuyResourcesState::Enter() {
	std::cout << "Entering Buy Resources State\n";
	m_pMarket = &pGameData->market;
	m_View.SetData(m_pMarket);
}

void CBuyResourcesState::Exit() {
	std::cout << "Exiting Buy Resources State\n";
}