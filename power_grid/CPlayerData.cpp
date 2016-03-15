#include "CPlayerData.h"

CPlayerData::CPlayerData(string name) :
	m_sName(name) {

}

CPlayerData::~CPlayerData() {

}

string CPlayerData::GetName() {
	return m_sName;
}

const string CPlayerData::GetName() const {
	return m_sName;
}

int CPlayerData::GetMoney() {
	return m_iMoney;
}

const int CPlayerData::GetMoney() const {
	return m_iMoney;
}

int CPlayerData::GetCoal() {
	return m_iCoal;
}

const int CPlayerData::GetCoal() const {
	return m_iCoal;
}

int CPlayerData::GetOil() {
	return m_iOil;
}

const int CPlayerData::GetOil() const {
	return m_iOil;
}

int CPlayerData::GetGarbage() {
	return m_iGarbage;
}

const int CPlayerData::GetGarbage() const {
	return m_iGarbage;
}

int CPlayerData::GetUranium() {
	return m_iUranium;
}

const int CPlayerData::GetUranium() const {
	return m_iUranium;
}