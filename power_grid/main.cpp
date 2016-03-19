#include "CGameController.h"

// Main States
#include "CMenuState.h"

#include "CGameData.h"
#include "config.h"

#include "base.h"

int main() {
	CGameController game;
	game.AddState("menustate", new CMenuState);
	game.AddState("gamestate", new CMenuState);
	game.ChangeState("menustate");
	return 0;
}