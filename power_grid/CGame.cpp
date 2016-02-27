#include "CGame.h"

CGame::CGame() {

}

CGame::~CGame() {

}

void CGame::Initialize() {
	std::cout << "How many players will be playing? ";
	std::cin >> m_iNumberOfPlayers;


	InitializePlayers();
	InitializeBoard();
	InitializeDeck();

	// Print Everything we (the driver) has
	PrintResourceMarket();

	// buy some stuff
	m_vPlayers[0].AttemptToBuyCoal();
	m_vPlayers[0].AttemptToBuyOil();
	m_vPlayers[0].AttemptToBuyGarbage();
	m_vPlayers[0].AttemptToBuyUranium();

	// look at all out loot
	m_vPlayers[0].Print();

	// take a look at the market
	PrintResourceMarket();

	// Test the deck
	CDeck deck;
	deck.Draw().Print();
}

int CGame::NumberOfPlayers() {
	return m_iNumberOfPlayers;
}

const int CGame::NumberOfPlayers() const {
	return m_iNumberOfPlayers;
}

int CGame::CurrentPhase() {
	return 0;
}

const int CGame::CurrentPhase() const {
	return 0;
}

void CGame::InitializePlayers() {
	for (int i = 0; i < m_iNumberOfPlayers; i++) {
		std::string temp;
		std::cout << "What is player " << (i+1) << "'s name? ";
		std::cin >> temp;

		m_vPlayers.push_back(CPlayer(temp));
	}
}

void CGame::InitializeBoard() {

}

void CGame::InitializeDeck() {

}

