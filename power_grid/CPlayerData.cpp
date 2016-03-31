#include "CPlayerData.h"

CPlayerData::CPlayerData() : CPlayerData(NULL) {

}

CPlayerData::CPlayerData(string name) :
	m_sName(name),
	m_iMoney(50),
	m_iCoal(0),
	m_iOil(0),
	m_iGarbage(0),
	m_iUranium(0),
	m_iMaxCoal(0),
	m_iMaxOil(0),
	m_iMaxGarbage(0),
	m_iMaxUranium(0) {
	Notify();
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

int CPlayerData::GetMaxCoal() {
	return m_iMaxCoal;
}

const int CPlayerData::GetMaxCoal() const {
	return m_iMaxCoal;
}

int CPlayerData::GetMaxOil() {
	return m_iMaxOil;
}

const int CPlayerData::GetMaxOil() const {
	return m_iMaxOil;
}

int CPlayerData::GetMaxGarbage() {
	return m_iMaxGarbage;
}

const int CPlayerData::GetMaxGarbage() const {
	return m_iMaxGarbage;
}

int CPlayerData::GetMaxUranium() {
	return m_iMaxUranium;
}

const int CPlayerData::GetMaxUranium() const {
	return m_iMaxUranium;
}

void CPlayerData::BuyCoal() {
	m_iCoal++;
}

void CPlayerData::BuyOil() {
	m_iOil++;
}

void CPlayerData::BuyGarbage() {
	m_iGarbage++;
}

void CPlayerData::BuyUranium() {
	m_iUranium++;
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

void CPlayerData::BuyCard(CCardData* card) {
	m_vCard.push_back(card);
	int num = card->GetCost();
	int resource = card->GetResources();
	switch (resource)
	{
	case 1:
		m_iMaxCoal += num * 2;
		break;
	case 10:
		m_iMaxOil += num * 2;
		break;
	case 11:
		m_iMaxCoal += num * 2;
		m_iMaxOil += num * 2;
		break;
	case 100:
		m_iMaxGarbage += num * 2;
		break;
	case 1000:
		m_iMaxUranium += num * 2;
		break;
	default:
		break;
	}
}

void CPlayerData::BuyCity(CCityData* city) {
	CHouseData newHouse(city);
	m_vHouse.push_back(newHouse);
	m_iMoney -= city->GetCost();
}

void CPlayerData::ConsumeMoney(int amount) {
	m_iMoney -= amount;
}

GenerateResults_e CPlayerData::GenerateElectricity(int cardNum) {
	int cost = m_vCard[cardNum]->GetCost();
	int fuelType = m_vCard[cardNum]->GetResources();
	int powers = m_vCard[cardNum]->GetCitiesPowered();

	switch (fuelType)
	{
	case 0:
		m_iNumberOfCitiesPoweredThisTurn += powers;
		return GENERATE_SUCCEED;
	case 1:
		if (m_iCoal < cost) {
			return GENERATE_NOT_ENOUGH_FUEL;
		}
		else {
			m_iCoal -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
	case 10:
		if (m_iOil < cost) {
			return GENERATE_NOT_ENOUGH_FUEL;
		}
		else {
			m_iOil -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
	case 11:
		if (m_iCoal < cost) {
			if (m_iOil < cost) {
				return GENERATE_NOT_ENOUGH_FUEL;
			}
			else
				m_iOil -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
		else {
			m_iCoal -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
	case 100:
		if (m_iGarbage < cost) {
			return GENERATE_NOT_ENOUGH_FUEL;
		}
		else {
			m_iGarbage -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
	case 1000:
		if (m_iUranium < cost) {
			return GENERATE_NOT_ENOUGH_FUEL;
		}
		else {
			m_iUranium -= cost;
			m_iNumberOfCitiesPoweredThisTurn += powers;
			return GENERATE_SUCCEED;
		}
	default:
		break;
	}
}

int CPlayerData::GetIncome() {
	//The number of cities that could be powered this turn won't be greater than the cities a player owns
	int powerNumber = (m_iNumberOfCitiesPoweredThisTurn > (int)m_vHouse.size() ? (int)m_vHouse.size() : m_iNumberOfCitiesPoweredThisTurn);
	int income;
	switch (powerNumber) {
	case 0:
		income = 10;
		break;
	case 1:
		income = 22;
		break;
	case 2:
		income = 33;
		break;
	case 3:
		income = 44;
		break;
	case 4:
		income = 54;
		break;
	case 5:
		income = 64;
		break;
	case 6:
		income = 73;
		break;
	case 7:
		income = 82;
		break;
	case 8:
		income = 90;
		break;
	case 9:
		income = 98;
		break;
	case 10:
		income = 105;
		break;
	case 11:
		income = 112;
		break;
	case 12:
		income = 118;
		break;
	case 13:
		income = 124;
		break;
	case 14:
		income = 129;
		break;
	case 15:
		income = 134;
		break;
	case 16:
		income = 138;
		break;
	case 17:
		income = 142;
		break;
	case 18:
		income = 145;
		break;
	case 19:
		income = 148;
		break;
	case 20:
		income = 150;
		break;
	}
	m_iMoney += income;
	m_iNumberOfCitiesPoweredThisTurn = 0;
	return income;
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
		XMLAppendAttribute(house, "cityName", m_vHouse[i].GetCity()->GetName());
	}
	
}
