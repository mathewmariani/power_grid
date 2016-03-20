#include "CMenuState.h"
#include "CGameController.h"

CMenuState::CMenuState() {

}

CMenuState::~CMenuState() {

}


void CMenuState::Enter() {
	std::cout << "NEW GAME!\n";
	//m_pOwner->LoadState("initstate");
	//data.Attach(&view);
	//view.SetData(&data);
	//view.Render();

	//HandleInput();
}

void CMenuState::Exit() {
	//data.Detach(&view);
	//std::cout << "Exiting\n";
}

void CMenuState::HandleInput() {
	while (data.GetState() == SELECTION_NONE) {
		int input = 0;
		std::cin >> input;

		data.SelectMenuOption(input);
	}

	switch (data.GetState()) {
	case SELECTION_NEW:
		std::cout << "NEW GAME!\n";
		//m_pOwner->LoadState("initstate");
		break;
	case SELECTION_LOAD:
		// MAT: Add Logic here to load last saved game!
		std::cout << "Load last game!\n";
		break;
	default:
		break;
	}
}