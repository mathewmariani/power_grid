#pragma once

#include "CCity.h"
#include "base.h"

class CMap {
public:
	CMap();
	~CMap();

	// MAT: This should eventually override << operator
	void Print() {
		for (auto& x : m_vCities) {
			x.Print();
		}
	}
	void Serialize(pugi::xml_node &parent);
	void AddCity(std::string name, std::string region);

	CCity GetCityByName(std::string name);

private:
	std::vector<CCity> m_vCities;
};