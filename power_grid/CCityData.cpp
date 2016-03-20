#include "CCityData.h"

CCityData::CCityData(std::string name, std::string region) :
	m_sName(name),
	m_sRegion(region) {

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

void CCityData::AddNeighbour(string name, int cost) {
	m_vConnections[name] = cost;
	Notify();
}

void CCityData::AddHouse(CHouseData* house) {
	m_vHouses.push_back(house);
	Notify();
}

int CCityData::GetHouses() {
	return m_vHouses.size();
}