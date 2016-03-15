#include "CTurnOrderState.h"

CTurnOrderState::CTurnOrderState() {

}

CTurnOrderState::~CTurnOrderState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CTurnOrderState::Enter() {
	std::cout << "Entering Turn Order State\n";
}

void CTurnOrderState::Exit() {
	std::cout << "Exiting Turn Order State\n";
}
