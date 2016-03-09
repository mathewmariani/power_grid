#pragma once

#include "ISerializable.h"
#include "CDeck.h"
#include "CPlayer.h"
#include "base.h"

enum GameState_e {
	STATE_PLACEHOLDER_ONE,
	STATE_PLACEHOLDER_TWO,
	STATE_PLACEHOLDER_THREE,
	STATE_PLACEHOLDER_FOUR,
};

class CGame {
public:
	CGame();
	~CGame();

	void Initialize();

	int NumberOfPlayers();
	const int NumberOfPlayers() const;

	GameState_e CurrentState();
	const GameState_e CurrentState() const;

	void Save();
	void Load();
	void LoadPlayers(std::string name);

	void SortOrder();

private:
	void InitializePlayers();
	void InitializeBoard();
	void InitializeDeck();


	int m_iCurrentPhase;

	int m_iNumberOfPlayers;
	std::vector<CPlayer> m_vPlayers;
};

//sorting order function, make it a global function
bool CompareFunction(const CPlayer &p1, const CPlayer &p2);