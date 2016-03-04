#pragma once

#include "CResourceMarket.h"
#include "CCard.h"
#include "CDeck.h"
#include "base.h"

enum BuyResult_e {
	BUY_BOUGHT,
	BUY_CANT_AFFORD,
};

enum GenerateResult_e {
	GENERATE_NOT_ENOUGH_RESOURCE,
	GENERATE_SUCCEED,
};

class CPlayer {
public:
	CPlayer(std::string name);
	~CPlayer();

	std::string GetName();
	int GetMoney();
	int GetCoal();
	int GetOil();
	int GetGarbage();
	int GetUranium();

	const std::string GetName() const;
	const int GetMoney() const;
	const int GetCoal() const;
	const int GetOil() const;
	const int GetGarbage() const;
	const int GetUranium() const;

	// override << Operator
	void Print() {
		std::cout << "Player Info===================" << "\n";
		std::cout << "NAME:\t\t" << m_sName << "\n\n";
		std::cout << "MONEY:\t\t" << m_iMoney << "\n";
		std::cout << "COAL:\t\t" << m_iCoal << "\n";
		std::cout << "OIL:\t\t" << m_iOil << "\n";
		std::cout << "GARBAGE:\t" << m_iGarbage << "\n";
		std::cout << "URANIUM:\t" << m_iUranium << "\n";
		std::cout << "==============================" << "\n";
	}

	BuyResult_e AttemptToBuyCoal();
	BuyResult_e AttemptToBuyOil();
	BuyResult_e AttemptToBuyGarbage();
	BuyResult_e AttemptToBuyUranium();

	BuyResult_e AttemptToBuyPlantCard(CDeck* deck, int cardNumber);

	GenerateResult_e GenerateEletricity(int cardNum);

private:
	std::string m_sName;

	int m_iMoney;

	// Resources
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;

	//Plant cards
	CCard m_iCard[3];
	int m_iNumberOfPlantCards;

	int m_iNumberOfCitiesPoweredThisTurn;
};