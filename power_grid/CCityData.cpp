#include "CCityData.h"

CCityData::CCityData(std::string name, std::string region) :
	m_sName(name),
	m_sRegion(region),
	m_iCountHouses(0) {

}

CCityData::~CCityData() {

}

string CCityData::GetName() {
	return m_sName;
}

const string CCityData::GetName() const {
	return m_sName;
}

string CCityData::GetRegion() {
	return m_sRegion;
}

const string CCityData::GetRegion() const {
	return m_sRegion;
}

string CCityData::GetNeighbours() {
	string neighbours = "";
	for (auto &i : m_vConnections) {
		neighbours = neighbours + i.first + ", ";
	}
	return neighbours;
}

void CCityData::AddNeighbour(std::string name, int cost) {
	// MAT: Im very surprised this works LOL
	//std::cout << name << ": " << cost << std::endl;
	m_vConnections.insert({ name, cost });

}

void CCityData::IncreaseCount() {
	m_iCountHouses++;
}

int CCityData::GetCost() {
	return (10 + m_iCountHouses * 5);
}