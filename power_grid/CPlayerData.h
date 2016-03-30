#pragma once

#include "base.h"
#include "CCardData.h"
#include "CHouseData.h"

// Common
#include "ISubject.h"

enum GenerateResults_e {
	GENERATE_NOT_ENOUGH_FUEL,
	GENERATE_SUCCEED
};

class CPlayerData : ISubject {
public:
	CPlayerData();
	CPlayerData(string name);
	CPlayerData(std::string name, int money, int coal, int oil, int garbage, int uranium, std::vector<CCardData *> cards);
	~CPlayerData();

	string GetName();
	const string GetName() const;

	int GetMoney();
	const int GetMoney() const;

	int GetCoal();
	const int GetCoal() const;

	int GetOil();
	const int GetOil() const;

	int GetGarbage();
	const int GetGarbage() const;

	int GetUranium();
	const int GetUranium() const;

	int GetMaxCoal();
	const int GetMaxCoal() const;

	int GetMaxOil();
	const int GetMaxOil() const;

	int GetMaxGarbage();
	const int GetMaxGarbage() const;

	int GetMaxUranium();
	const int GetMaxUranium() const;

	void BuyCoal();
	void BuyOil();
	void BuyGarbage();
	void BuyUranium();

	std::vector<CHouseData> GetHouse();
	const std::vector<CHouseData> GetHouse() const;

	std::vector<CCardData *> GetCard();
	const std::vector<CCardData *> GetCard() const;

	void BuyCard(CCardData* card);

	void BuyCity(CCityData* city);

	void ConsumeMoney(int amount);

	GenerateResults_e GenerateElectricity(int cardNum);

	int GetIncome();

	void Serialize(pugi::xml_node &parent);

private:
	string m_sName;

	int m_iMoney;
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;

	//The max amount of resoures a player can buy
	int m_iMaxCoal;
	int m_iMaxOil;
	int m_iMaxGarbage;
	int m_iMaxUranium;

	int m_iNumberOfCitiesPoweredThisTurn;

	std::vector<CCardData *> m_vCard;
	std::vector<CHouseData> m_vHouse;
};