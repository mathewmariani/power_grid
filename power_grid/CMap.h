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
	void addCity(std::string name, std::string region);

private:
	std::vector<CCity> m_vCities;
};