#include "CGameController.h"

// Main States
#include "CMenuState.h"
#include "CInitializeState.h"
#include "CGameState.h"

#include "base.h"
//#include "CMapData.h"
//#include "CMapView.h"

int main() {

	//CGameController game;
	//game.AddState("menustate", new CMenuState);			// Decide if were loading or starting a new
	//game.AddState("initstate", new CInitializeState);		// Create new game
	//game.AddState("gamestate", new CGameState);			// where the game happens
	//game.LoadState("menustate");

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