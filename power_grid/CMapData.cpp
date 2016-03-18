#pragma once
#include "CMapData.h"

CMapData::CMapData() {}
CMapData::~CMapData() {}

void CMapData::Serialize(pugi::xml_node &parent) {
	//ANDRES: serialization goes here
}

void CMapData::AddCity(std::string name, std::string region) {
	m_vCities.push_back(CCityData(name, region));
}

CCityData CMapData::GetCityByName(std::string name) {
	for (int i = 0; i < m_vCities.size(); i++) {
		if (std::strcmp(m_vCities[i].GetName().c_str(), name.c_str()) == 0)
			return m_vCities[i];
	}
}
