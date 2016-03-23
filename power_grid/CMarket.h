#pragma once

// Common
#include "ISubject.h"

#include "base.h"


class CMarket : public ISubject {
public:
	CMarket();
	CMarket(int coal, int oil, int garbage, int uranium);
	~CMarket();

	int GetCoal();
	const int GetCoal() const;
	void SellCoal();

	int GetOil();
	const int GetOil() const;
	void SellOil();

	int GetGarbage();
	const int GetGarbage() const;
	void SellGarbage();

	int GetUranium();
	const int GetUranium() const;
	void SellUranium();

	int GetCostOfCoal();
	const int GetCostOfCoal() const;

	int GetCostOfOil();
	const int GetCostOfOil() const;

	int GetCostOfGarbage();
	const int GetCostOfGarbage() const;

	int GetCostOfUranium();
	const int GetCostOfUranium() const;

private:
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;
};