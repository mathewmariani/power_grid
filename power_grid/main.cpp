#include "CGameController.h"

// Main States
#include "CMenuState.h"
#include "CGameState.h"

#include "base.h"
//#include "CMapData.h"
//#include "CMapView.h"

#include "CMarket.h"
#include "CMarketView.h"

#include "CBuyPowerPlantState.h"
#include "CBuyResourcesState.h"

int main() {

	CPlayerData p1("aaa");
	CPlayerData p2("bbb");
	CPlayerData p3("ccc");
	CPlayerData p4("ddd");

	pGameData->playerList.push_back(p1);
	pGameData->playerList.push_back(p2);
	pGameData->playerList.push_back(p3);
	pGameData->playerList.push_back(p4);

	CBuyResourcesState state;
	state.Enter();
	state.Start();

	return 0;
}