#include "CGameData.h"

static CGameData _gameData;
CGameData *pGameData = &_gameData;

CGameData::CGameData() :
	currentRound(0),
	currentTime(0.0f) {
}

void CGameData::Print() {
	std::cout << "There are " << playerList.size() << " players:\n";
	for (int i = 0; i < playerList.size(); i++)
		std::cout << i + 1 << ". " << playerList[i].GetName() << "\n";
}
