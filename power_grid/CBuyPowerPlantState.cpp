#include "CGameController.h"
#include "CBuyPowerPlantState.h"


CBuyPowerPlantState::CBuyPowerPlantState() {

}

CBuyPowerPlantState::~CBuyPowerPlantState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CBuyPowerPlantState::Start() {
	std::cout << "Start Buy Power Plant State\n";

	int round = 1;
	int biddingPrice, index;

	std::vector<CPlayerData *> biddersThisRound;
	std::vector<CPlayerData *> bidderList;
	for (int i = 0; i < pGameData->playerList.size(); i++) {
		bidderList.push_back(&pGameData->playerList[i]);
	}

	while (bidderList.size() != 0) {
		biddersThisRound.clear();
		std::cout << "Round " << round << "\n";
		std::cout << "Player " << bidderList.front()->GetName() << "'s turn to start a bid.\n";

		std::cout << "Please type in the index(From 1 to 4, 0 represents abandon):\n";
		std::cin >> index;
		if (index == 0) {
			std::cout << "Player " << bidderList.front()->GetName() << " abandoned bidding!\n";
			bidderList.erase(bidderList.begin());
			round++;
			continue;
		}
		else {
			std::cout << "Please type in the price:\n";
			std::cin >> biddingPrice;
			biddersThisRound.push_back(bidderList.front());
		}

		for (int i = 1; i < bidderList.size(); i++) {
			std::cout << "Player " << bidderList[i]->GetName() << "'s turn to bid.\n";
			std::cout << "Please type in your bidding price:\n";
			int temp;
			std::cin >> temp;
			if (temp == 0) {
				std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
			}
			else {
				biddingPrice = temp;
				biddersThisRound.push_back(bidderList[i]);
			}
		}

		while (biddersThisRound.size() > 1) {
			for (int i = 0; i < biddersThisRound.size(); i++) {
				std::cout << "Player " << bidderList[i]->GetName() << "'s turn to bid.\n";
				std::cout << "Please type in your bidding price:\n";
				int temp;
				std::cin >> temp;
				if (temp == 0) {
					std::cout << "Player " << bidderList[i]->GetName() << " abandoned bidding!\n";
					biddersThisRound.erase(biddersThisRound.begin() + i);
				}
				else {
					biddingPrice = temp;
				}
			}

		}

		std::cout << "Player " << biddersThisRound[0]->GetName() << " bought plant card finally!\n\n";
		biddersThisRound[0]->ConsumeMoney(biddingPrice);
		biddersThisRound[0]->BuyCard(pGameData->deck.PlayerBuysCard(index - 1));
		for (int i = 0; i < bidderList.size(); i++) {
			if (bidderList[i] == biddersThisRound[0]) {
				bidderList.erase(bidderList.begin() + i);
				break;
			}
		}
		round++;
	}
	m_pOwner->NextPhase();
}

void CBuyPowerPlantState::Enter() {
	std::cout << "Entering Buy Power Plant State\n";
}

void CBuyPowerPlantState::Exit() {
	std::cout << "Exiting Buy Power Plant State\n";
}