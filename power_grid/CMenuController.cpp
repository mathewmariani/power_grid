#include "CMenuController.h"

CMenuController::CMenuController() {
	m_MenuData.Attach(this);
	//m_MenuView.Initialize(&m_MenuData);

	while (m_MenuData.GetState() == SELECTION_NONE) {
		int input = 0;
		std::cin >> input;

		m_MenuData.SelectMenuOption(input);
	}
}

CMenuController::~CMenuController() {

}

void CMenuController::Update() {
	switch (m_MenuData.GetState()) {
	case SELECTION_NONE:
		std::cout << "SELECTION_NONE" << std::endl;
		break;
	case SELECTION_NEW:
		std::cout << "SELECTION_NEW" << std::endl;
		break;
	case SELECTION_LOAD:
		std::cout << "SELECTION_LOAD" << std::endl;
		break;
	}
}
