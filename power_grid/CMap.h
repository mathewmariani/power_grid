#pragma once

#include "CCity.h"
#include "base.h"

class CMap {
public:
	CMap(std::string name);
	~CMap();

	std::string GetMapName();
	const std::string GetMapName() const;

	void AddCity(std::string name, std::string region);
	CCity GetCityByName(std::string name);

	void Serialize(pugi::xml_node &parent);

	// MAT: This should eventually override << operator
	void Print() {
		for (auto& x : m_vCities) {
			x.Print();
		}
	}

private:
	std::vector<CCity> m_vCities;
	std::string m_sName;
};