#include "CMapData.h"

CMapData::CMapData() {}
CMapData::~CMapData() {}

void CMapData::Serialize(pugi::xml_node &parent) {
	//ANDRES: serialisation goes here when we decide
	//to write it
}

void CMapData::AddCity(std::string name, std::string region) {
	m_vCities.push_back(CCityData(name, region));
	Notify();
}

CCityData CMapData::GetCityByName(std::string name) {
	for (int i = 0; i < m_vCities.size(); i++) {
		if (std::strcmp(m_vCities[i].GetName().c_str(), name.c_str()) == 0)
			return m_vCities[i];
	}
}

void CMapData::DisplayCities() {
	for (CCityData city : m_vCities) {
		std::cout << "City: " << city.GetName() << ", " << city.GetRegion() << std::endl;
		std::cout << "\tNeighbours: " << city.GetNeighbours();
	}
}