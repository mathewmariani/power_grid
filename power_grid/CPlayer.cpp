#include "CPlayer.h"
#include "shareddef.h"
#include <iostream>

CPlayer::CPlayer(std::string name) :
	m_sName(name),
	m_iMoney(STARTING_ELECTRO),
	m_iCoal(0),
	m_iOil(0),
	m_iGarbage(0),
	m_iUranium(0),
	m_iNumberOfCitiesPoweredThisTurn(0),	// not needed here    Junan: it must be initialized to 0
	m_iMaxCardNum(0) {	// not needed here can be calculated      Junan: it must be initialized to 0

}

CPlayer::CPlayer(std::string name, int money, int coal, int oil, int garbage, int uranium, std::vector<CCard> card) :
	m_sName(name),
	m_iCoal(coal),
	m_iOil(oil),
	m_iGarbage(garbage),
	m_iUranium(uranium),
	m_vCard(card),	// not needed here
	m_vHouse(),	// not needed here
	m_iNumberOfCitiesPoweredThisTurn(0),	// not needed here
	m_iMaxCardNum(0) {	// not needed here can be calculated

}


CPlayer::~CPlayer() {

}

std::string CPlayer::GetName() {
	return m_sName;
}

int CPlayer::GetMoney() {
	return m_iMoney;
}

int CPlayer::GetCoal() {
	return m_iCoal;
}

int CPlayer::GetOil() {
	return m_iOil;
}

int CPlayer::GetGarbage() {
	return m_iGarbage;
}

int CPlayer::GetUranium() {
	return m_iUranium;
}

int CPlayer::GetMaxCardNum() {
	return m_iMaxCardNum;
}

std::vector<CCard> CPlayer::GetCard() {
	return m_vCard;
}

std::vector<CHouse> CPlayer::GetHouse() {
	return m_vHouse;
}

const std::string CPlayer::GetName() const {
	return m_sName;
}

const int CPlayer::GetMoney() const {
	return m_iMoney;
}

const int CPlayer::GetCoal() const {
	return m_iCoal;
}

const int CPlayer::GetOil() const {
	return m_iOil;
}

const int CPlayer::GetGarbage() const {
	return m_iGarbage;
}

const int CPlayer::GetUranium() const {
	return m_iUranium;
}

const int CPlayer::GetMaxCardNum() const {
	return m_iMaxCardNum;
}

const std::vector<CCard> CPlayer::GetCard() const {
	return m_vCard;
}

const std::vector<CHouse> CPlayer::GetHouse() const {
	return m_vHouse;
}

BuyResult_e CPlayer::AttemptToBuyCoal() {
	int iCoalPrice = CostOfCoal();

	if (m_iMoney < iCoalPrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}
	else if (g_iCoalCount == 0) {
		std::cout << "#Not_Enough_Resources\n";
		return BUY_CANT_AFFORD;
	}
	else {
		ResourceMarketSellResource(RESOURCE_COAL);
		m_iMoney -= iCoalPrice;
		m_iCoal++;

		std::cout << "#Bought_Resource_Coal\n";

		return BUY_BOUGHT;
	}
}

BuyResult_e CPlayer::AttemptToBuyOil() {
	int iOilPrice = CostOfOil();

	if (GetMoney() < iOilPrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}
	else if (g_iOilCount == 0) {
		std::cout << "#Not_Enough_Resources\n";
		return BUY_CANT_AFFORD;
	}
	else {
		ResourceMarketSellResource(RESOURCE_OIL);
		m_iMoney -= iOilPrice;
		m_iOil++;

		std::cout << "#Bought_Resource_Oil\n";

		return BUY_BOUGHT;
	}
}

BuyResult_e CPlayer::AttemptToBuyGarbage() {
	int iGarbagePrice = CostOfGarbage();

	if (GetMoney() < iGarbagePrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}
	else if (g_iGarbageCount == 0) {
		std::cout << "#Not_Enough_Resources\n";
		return BUY_CANT_AFFORD;
	}
	else {
		ResourceMarketSellResource(RESOURCE_GARBAGE);
		m_iMoney -= iGarbagePrice;
		m_iGarbage++;

		std::cout << "#Bought_Resource_Garbage\n";

		return BUY_BOUGHT;
	}
}

BuyResult_e CPlayer::AttemptToBuyUranium() {
	int iUraniumPrice = CostOfUranium();

	if (GetMoney() < iUraniumPrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}
	else if (g_iUraniumCount == 0) {
		std::cout << "#Not_Enough_Resources\n";
		return BUY_CANT_AFFORD;
	}
	else {
		ResourceMarketSellResource(RESOURCE_URANIUM);
		m_iMoney -= iUraniumPrice;
		m_iUranium++;

		std::cout << "#Bought_Resource_Uranium\n";

		return BUY_BOUGHT;
	}
}

BuyResult_e CPlayer::AttemptToBuyCard(CDeck* deck, int cardNumber) {
	CCard card = deck->FindCard(cardNumber);
	int cardPrice = card.GetCost();

	if (GetMoney() < cardPrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}

	else if (cardPrice == 0) {
		std::cout << "#Plant_Card_Not_Available\n";
		return BUY_CANT_AFFORD;
	}

	else {
		m_vCard.push_back(card);
		m_iMoney -= cardPrice;
		//update the maximal card number
		if (card.GetNumber() > m_iMaxCardNum)
			m_iMaxCardNum = card.GetNumber();

		std::cout << "#Bought_Plant_Card_Number" << cardNumber << "\n";
		return BUY_BOUGHT;
	}
}

GenerateResult_e CPlayer::GenerateEletricity(int cardNum) {
	CCard card = m_vCard[cardNum];
	int fuelType = card.GetResources();
	int cost = card.GetCost();

	// MAT: Use bitwise operations since thats how i decided to store the cards
	if ((card.GetResources() & (RESOURCE_GARBAGE | RESOURCE_OIL)) == (RESOURCE_GARBAGE | RESOURCE_OIL)) {
		if (m_iCoal < cost) {
			if (m_iOil < cost)
				return GENERATE_NOT_ENOUGH_RESOURCE;
			else
				m_iOil -= cost;
		}
		else {
			m_iCoal -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	} else if ((card.GetResources() & RESOURCE_COAL) == RESOURCE_COAL) {
		if (m_iCoal < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iCoal -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	} else if ((card.GetResources() & RESOURCE_OIL) == RESOURCE_OIL) {
		if (m_iOil < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iOil -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	} else if ((card.GetResources() & RESOURCE_GARBAGE) == RESOURCE_GARBAGE) {
		if (m_iGarbage < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iGarbage -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	} else if ((card.GetResources() & RESOURCE_URANIUM) == RESOURCE_URANIUM) {
		if (m_iUranium < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iUranium -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	} else if ((card.GetResources() & RESOURCE_NONE) == RESOURCE_NONE) {
		m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
		return GENERATE_SUCCEED;
	} else {
		return GENERATE_NOT_ENOUGH_RESOURCE;
	}
}

//According to the cities powered this turn, players get the corresponding incomes.
// MAT: Can this be calculated in anyway? I don't like giant switch statments.
// Junan: I don't like this way either but it seems calculation way is also lengthy
void CPlayer::GetIncome() {
	//The number of cities that could be powered this turn won't be greater than the cities a player owns
	// warning C4267 : 'initializing' : conversion from 'size_t' to 'int', possible loss of data
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
}


void CPlayer::BuildHouseOn(CCity city) {
	//Code for computing the required money to buy a city
	CHouse house(city);
	m_vHouse.push_back(house);
}

void CPlayer::Serialize(pugi::xml_node &parent) {
	auto player = XMLAppendChild(parent, "player");
	XMLAppendAttribute(player, "name", GetName());
	XMLAppendAttribute(player, "money", GetMoney());
	XMLAppendAttribute(player, "coal", GetCoal());
	XMLAppendAttribute(player, "oil", GetOil());
	XMLAppendAttribute(player, "garbage", GetGarbage());
	XMLAppendAttribute(player, "uranium", GetUranium());
}