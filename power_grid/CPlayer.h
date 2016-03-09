#pragma once

#include "ISerializable.h"

#include "CResourceMarket.h"
#include "CCard.h"
#include "CDeck.h"
#include "CHouse.h"
#include "CCity.h"

#include "base.h"

// MAT: These aren't actually needed,
// But leave them in just incase
enum BuyResult_e {
	BUY_BOUGHT,
	BUY_CANT_AFFORD,
};

// MAT: These aren't actually needed,
// But leave them in just incase
enum GenerateResult_e {
	GENERATE_NOT_ENOUGH_RESOURCE,
	GENERATE_SUCCEED,
};

class CPlayer : ISerializable {
public:
	CPlayer(std::string name);
	CPlayer(std::string name, int money, int coal, int oil, int garbage, int uranium, std::vector<CCard> card);
	~CPlayer();

	std::string GetName();
	int GetMoney();
	int GetCoal();
	int GetOil();
	int GetGarbage();
	int GetUranium();
	int GetMaxCardNum();
	std::vector<CCard> GetCard();
	std::vector<CHouse> GetHouse();

	const std::string GetName() const;
	const int GetMoney() const;
	const int GetCoal() const;
	const int GetOil() const;
	const int GetGarbage() const;
	const int GetUranium() const;
	const int GetMaxCardNum() const;
	const std::vector<CCard> GetCard() const;
	const std::vector<CHouse> GetHouse() const;

	// MAT: This should eventually override << operator
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
	BuyResult_e AttemptToBuyCard(CDeck *deck, int cardNumber);

	GenerateResult_e GenerateEletricity(int cardNum);

	void BuildHouseOn(CCity city);
	void GetIncome();

	void Serialize(pugi::xml_node &parent);

private:
	std::string m_sName;

	int m_iMoney;

	// Resources
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;

	//Plant cards
	std::vector<CCard> m_vCard;
	int m_iMaxCardNum;

	//Houses
	std::vector<CHouse> m_vHouse;
	
	int m_iNumberOfCitiesPoweredThisTurn;
};