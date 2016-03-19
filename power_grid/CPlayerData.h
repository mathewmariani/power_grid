#pragma once

#include "base.h"
#include "CCardData.h"
#include "CHouseData.h"

class CPlayerData {
public:
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

	std::vector<CHouseData> GetHouse();
	const std::vector<CHouseData> GetHouse() const;

	std::vector<CCardData *> GetCard();
	const std::vector<CCardData *> GetCard() const;

	void Serialize(pugi::xml_node &parent);

private:
	string m_sName;

	int m_iMoney;
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;

	std::vector<CCardData *> m_vCard;
	
	std::vector<CHouseData> m_vHouse;

};