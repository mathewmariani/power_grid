#include "CPlayerData.h"

CPlayerData::CPlayerData(string name) :
	m_sName(name) {

}

CPlayerData::CPlayerData(std::string name, int money, int coal, int oil, int garbage, int uranium, std::vector<CCardData *> cards) :
	m_sName(name),
	m_iCoal(coal),
	m_iOil(oil),
	m_iGarbage(garbage),
	m_iUranium(uranium),
	m_vCard(cards) {
}

CPlayerData::~CPlayerData() {
//	delete m_vCard;
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

std::vector<CHouseData> CPlayerData::GetHouse() {
	return m_vHouse;
}

const std::vector<CHouseData> CPlayerData::GetHouse() const {
	return m_vHouse;
}

std::vector<CCardData *> CPlayerData::GetCard() {
	return m_vCard;
}

const std::vector<CCardData *> CPlayerData::GetCard() const {
	return m_vCard;
}

void CPlayerData::Serialize(pugi::xml_node &parent) {
	auto player = XMLAppendChild(parent, "player");
	XMLAppendAttribute(player, "name", GetName());
	XMLAppendAttribute(player, "money", GetMoney());
	XMLAppendAttribute(player, "coal", GetCoal());
	XMLAppendAttribute(player, "oil", GetOil());
	XMLAppendAttribute(player, "garbage", GetGarbage());
	XMLAppendAttribute(player, "uranium", GetUranium());

	
	for (int i = 0; i < m_vCard.size(); i++) {
		auto card = XMLAppendChild(player, "card");
		XMLAppendAttribute(card, "number", m_vCard[i]->GetNumber());
	}
	
	for (int i = 0; i < m_vHouse.size(); i++) {
		auto house = XMLAppendChild(player, "house");
		XMLAppendAttribute(house, "cityName", m_vHouse[i].GetCity());
	}
	
}
