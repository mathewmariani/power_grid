#include "CGameController.h"
#include "CMenuController.h"
#include "CGameData.h"
#include "config.h"

#include "base.h"

int main() {
	
	// MAT: Im still finishing up...

	/*
	//Saving simulation
	CPlayerData p1("aaa");
	CPlayerData p2("bbb");

	pGameData->playerList.push_back(p1);
	pGameData->playerList.push_back(p2);

	Config::SaveGame(pGameData);
	*/

	//Loading simulation
	Config::LoadGame(pGameData);
	pGameData->Print();
	return 0;
}