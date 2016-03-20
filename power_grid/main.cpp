#include "CGameController.h"

// Main States
#include "CMenuState.h"

#include "CGameData.h"
#include "config.h"

#include "base.h"
//#include "CMapData.h"
//#include "CMapView.h"

int main() {
	//CMapData testMap;
	//CMapView mapObserver;
	//mapObserver.Initialize(&testMap);
	//testMap.AddCity("Montréal", "Eastern Canada");
	//testMap.AddCity("Ottawa", "Golden Horseshoe");
	CGameController game;
	game.AddState("menustate", new CMenuState);
	game.AddState("gamestate", new CMenuState);
	game.ChangeState("menustate");
	return 0;
}