#pragma once

// Model
#include "CPlayerData.h"

#include "base.h"

class CGameData {
public:
	CGameData();

	int currentRound;
	float currentTime;

	vector<CPlayerData> playerList;
};

extern CGameData *pGameData;