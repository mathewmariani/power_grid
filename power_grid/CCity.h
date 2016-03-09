#pragma once

#include "base.h"

class CCity {
	// MAT: A city belongs to the map, let it have full access.
	friend class CMap;

public:
	CCity(std::string name, std::string region);
	~CCity();

	std::string GetName();
	const std::string GetName() const;

	std::string GetRegion();
	const std::string GetRegion() const;

	// MAT: This should eventually override << operator
	void Print() {
		std::cout << "City Info====================" << "\n";
		std::cout << "NAME:\t\t" << m_sName << "\n";
		std::cout << "REGION:\t\t" << m_sRegion << "\n";
		std::cout << "NEIGHBOURS:\t" << m_vConnections.size() << "\n";

		// loop over m_vConnections
		for (auto& x : m_vConnections) {
			std::cout << x.first << ": " << x.second << std::endl;
		}

		std::cout << "==============================" << "\n";
	}
	
	//ANDRES: as steps progress and houses get built, the cost
	//of building on a city increases
	int	GetCost();
	void ResetCount();
	int GetCount();

private:
	void AddNeighbour(std::string name, int cost);
	void IncreaseCount();

	std::string m_sName;
	std::string m_sRegion;
	int m_iCountHouses = 0;
	int	m_iCurrentCost;
	
	std::unordered_map<std::string, int> m_vConnections;
};