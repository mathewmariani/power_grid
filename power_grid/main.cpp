#include "CGameController.h"

// Main States
#include "CMenuState.h"
#include "CGameState.h"

#include "base.h"
//#include "CMapData.h"
//#include "CMapView.h"

#include "CMarket.h"
#include "CMarketView.h"

int main() {

	//CMapData testMap;
	//CMapView mapObserver;
	//mapObserver.Initialize(&testMap);
	//testMap.AddCity("Montréal", "Eastern Canada");
	//testMap.AddCity("Ottawa", "Golden Horseshoe");

	//CGameController game;
	//game.AddState("menu", new CMenuState);
	//game.AddState("game", new CGameState);
	//game.LoadState("menu");

	CMarket market;
	CMarketView view;

	market.Attach(&view);

	view.SetData(&market);
	view.Render();

	market.AttemptToBuyCoal();
	market.AttemptToBuyCoal();
	market.AttemptToBuyCoal();
	market.AttemptToBuyCoal();
	market.AttemptToBuyCoal();

	market.AttemptToBuyUranium();

	return 0;
}