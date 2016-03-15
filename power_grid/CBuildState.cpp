#include "CBuildState.h"

CBuildState::CBuildState() {

}

CBuildState::~CBuildState() {
}

void CBuildState::Enter() {
	std::cout << "Entering Building State\n";
}

void CBuildState::Exit() {
	std::cout << "Exiting Building State\n";
}