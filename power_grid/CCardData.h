#pragma once

#include "base.h"

class CCardData {
public:
	CCardData();
	CCardData(int number, int cost, int resources, int poweres);
	~CCardData();

	int GetNumber();
	const int GetNumber() const;

	int GetCost();
	const int GetCost() const;

	int GetResources();
	const int GetResources() const;

	int GetCitiesPowered();
	const int GetCitiesPowered() const;

	void Print();

private:
	int m_iNumber;
	int m_iResourceCost;
	int m_iResources;
	int m_iNumberOfCitiesPowered;
};