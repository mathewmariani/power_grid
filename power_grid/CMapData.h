
#pragma once

#include "CCityData.h"
#include "ISubject.h"
#include "base.h"

class CMapData : public ISubject {
public:
	CMapData();
	~CMapData();

	void Serialize(pugi::xml_node &parent);
	void AddCity(std::string name, std::string region);

	CCityData GetCityByName(std::string name);

private:
	std::vector<CCityData> m_vCities;
};