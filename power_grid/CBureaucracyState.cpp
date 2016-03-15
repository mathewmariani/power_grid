#include "CBureaucracyState.h"

CBureaucracyState::CBureaucracyState() {

}

CBureaucracyState::~CBureaucracyState() {
	// MAT: Vectors handle there own memory management so whatever.
}

void CBureaucracyState::Enter() {
	std::cout << "Entering Bureaucracy State\n";
}

void CBureaucracyState::Exit() {
	std::cout << "Exiting Bureaucracy State\n";
}