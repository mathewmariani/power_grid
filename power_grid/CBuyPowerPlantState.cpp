#include "CBuyPowerPlantState.h"

CBuyPowerPlantState::CBuyPowerPlantState() {

}

CBuyPowerPlantState::~CBuyPowerPlantState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CBuyPowerPlantState::Enter() {
	std::cout << "Entering Buy Power Plant State\n";
}

void CBuyPowerPlantState::Exit() {
	std::cout << "Exiting Buy Power Plant State\n";
}