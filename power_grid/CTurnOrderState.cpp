#include "CTurnOrderState.h"

CTurnOrderState::CTurnOrderState() {

}

CTurnOrderState::~CTurnOrderState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CTurnOrderState::Enter() {
	std::cout << "Entering Turn Order State\n";
	std::sort(pGameData->playerList.begin(), pGameData->playerList.end(), CompareFunction);
}

void CTurnOrderState::Exit() {
	std::cout << "Exiting Turn Order State\n";
}

bool CompareFunction(const CPlayerData &p1, const CPlayerData &p2) {
	if (p1.GetHouse().size() > p2.GetHouse().size()) {
		return true;
	}
	else if (p1.GetHouse().size() == p1.GetHouse().size()) {
		if (p1.GetCard().size() > p2.GetCard().size()) {
			return true;
		}
	}

	return false;
}