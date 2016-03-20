#include "CGameController.h"

// Main States
#include "CMenuState.h"

#include "CGameData.h"
#include "config.h"

#include "base.h"
/*
#include "CMapData.h"
#include "CMapView.h"

#include "CCityData.h"
#include "CCityView.h"
*/

int main() {
	/*
	CMapData testMap;
	CMapView mapObserver;
	mapObserver.Initialize(&testMap);

	CCityData city("Narshe", "Northern Continent");
	CCityView cityWatcher;
	cityWatcher.SetData(&city);
	city.AddNeighbour("Figaro", 4);

	testMap.AddCity(city);
	*/
	CGameController game;
	game.AddState("menustate", new CMenuState);
	game.AddState("gamestate", new CMenuState);
	game.ChangeState("menustate");
	return 0;
}