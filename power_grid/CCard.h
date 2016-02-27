#pragma once

#include "base.h"

class CCard {
public:
	CCard();
	CCard(int number, int cost, int resources, int poweres);
	~CCard();

	int GetNumber();
	int GetCost();
	int GetResources();
	int GetCitiesPowered();

	const int GetNumber() const;
	const int GetCost() const;
	const int GetResources() const;
	const int GetCitiesPowered() const;

	// override << Operator
	void Print() {
		std::cout << "==============================" << "\n";
		std::cout << "NUMBER:\t\t" << m_iNumber << "\n\n";
		std::cout << "COST:\t\t" << m_iResourceCost << "\n";
		std::cout << "RESOURCES:\t" << m_iResources << "\n";
		std::cout << "POWERS:\t\t" << m_iNumberOfCitiesPowered << "\n";
		std::cout << "==============================" << "\n";
	}

private:
	int m_iNumber;
	int m_iResourceCost;
	int m_iResources;
	int m_iNumberOfCitiesPowered;
};