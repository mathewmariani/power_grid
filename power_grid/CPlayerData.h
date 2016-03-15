#pragma once

#include "base.h"

class CPlayerData {
public:
	CPlayerData(string name);
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

private:
	string m_sName;

	int m_iMoney;
	int m_iCoal;
	int m_iOil;
	int m_iGarbage;
	int m_iUranium;
};