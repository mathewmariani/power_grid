#include "CInitializeGameState.h"

CInitializeGameState::CInitializeGameState() {

}

CInitializeGameState::~CInitializeGameState() {
	while (!observers.empty()) {
		delete observers.back();
		observers.pop_back();
	}
}

void CInitializeGameState::Enter() {
	InitializePlayers();
	InitializeBoard();
	InitializeDeck();
}

void CInitializeGameState::Exit() {

}

void CInitializeGameState::Attach(IObserver *observable) {
	if (observable == nullptr) {
		return;
	}

	observers.push_back(observable);
}

void CInitializeGameState::Detach(IObserver *observable) {
	if (observable == nullptr) {
		return;
	}

	// MAT: remove me from the vector
}

void CInitializeGameState::Notify() {
	for (int i = 0; i < observers.size(); i++) {
		observers[i]->Update();
	}
}

void CInitializeGameState::InitializePlayers() {
	int iValue = 0;
	
	std::cout << "How many players will be playing? ";
	std::cin >> iValue;

	for (int i = 0; i < iValue; i++) {
		std::string temp;
		std::cout << "What is player " << (i + 1) << "'s name? ";
		std::cin >> temp;

		m_vPlayers.push_back(CPlayerData(temp));
	}

	//randomize the order in the beginning
	std::random_shuffle(m_vPlayers.begin(), m_vPlayers.end());
}

void CInitializeGameState::InitializeBoard() {

}

void CInitializeGameState::InitializeDeck() {

}

std::vector<CPlayerData> CInitializeGameState::GetPlayers() {
	return m_vPlayers;
}

const std::vector<CPlayerData> CInitializeGameState::GetPlayers() const {
	return m_vPlayers;
}