#include "CGameData.h"

static CGameData _gameData;
CGameData *pGameData = &_gameData;

CGameData::CGameData() :
	currentRound(0),
	currentTime(0.0f) {
}
