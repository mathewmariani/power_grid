#include "CCity.h"

CCity::CCity(std::string name, std::string region) :
	m_sName(name),
	m_sRegion(region) {

}

CCity::~CCity() {

}

std::string CCity::GetName() {
	return m_sName;
}
const std::string CCity::GetName() const {
	return m_sName;
}

std::string CCity::GetRegion() {
	return m_sRegion;
}

const std::string CCity::GetRegion() const {
	return m_sRegion;
}

// MAT: We have three options
// 1. we can use an unordered_map
// which will tell us our connections out of this city
// but requires looping over all cities to find the matching city

// or we can restructure the map file to create all the cities
// AND THEN add its neighbours..

// or during parsing we can loop over all the cities, and create them
// then loop over the cities again, and add there neighbours
// which will require us to loop over another vector to find the right city.

// im just going with option one, if anyone disagrees?
void CCity::AddNeighbour(std::string name, int cost) {
	// MAT: Im very surprised this works LOL
	//std::cout << name << ": " << cost << std::endl;
	m_vConnections.insert({ name, cost });

}