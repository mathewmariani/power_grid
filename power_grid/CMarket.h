#pragma once

// Common
#include "ISubject.h"

#include "base.h"

enum BuyResults_e {
	BUY_INSUFICIENT_FUNDS,
	BUY_NOT_ENOUGH_RESOURCE,
	BUY_SUCCEED,
};

class CMarket : public ISubject {
public:
	CMarket();
	CMarket(int coal, int oil, int garbage, int uranium);
	~CMarket();

	int GetCoal();
	const int GetCoal() const;
	BuyResults_e AttemptToBuyCoal();

	int GetOil();
	const int GetOil() const;
	BuyResults_e AttemptToBuyOil();

	int GetGarbage();
	const int GetGarbage() const;
	BuyResults_e AttemptToBuyGarbage();

	int GetUranium();
	const int GetUranium() const;
	BuyResults_e AttemptToBuyUranium();

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