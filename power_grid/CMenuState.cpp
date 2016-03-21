#include "CMenuState.h"
#include "CGameController.h"

CMenuState::CMenuState() {

}

CMenuState::~CMenuState() {

}

void CMenuState::Start() {
	HandleInput();
}

void CMenuState::Enter() {
	data.Attach(&view);
	view.SetData(&data);
	view.Render();
}

void CMenuState::Exit() {
	data.Detach(&view);
	system("cls");
}

void CMenuState::HandleInput() {
	while (data.GetState() == SELECTION_NONE) {
		int input = 0;
		std::cin >> input;

		data.SelectMenuOption(input);
	}

	switch (data.GetState()) {
	case SELECTION_NEW:
		m_pOwner->LoadState("init");
		break;
	case SELECTION_LOAD:
		// MAT: Add Logic here to load last saved game!
		std::cout << "Load last game!\n";
		break;
	default:
		break;
	}
}