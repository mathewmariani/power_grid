#include "CPlayer.h"
#include "shareddef.h"

CPlayer::CPlayer(std::string name) :
	m_sName(name),
	m_iMoney(STARTING_ELECTRO),
	m_iCoal(0),
	m_iOil(0),
	m_iGarbage(0),
	m_iUranium(0),
	m_iCard(),
	m_iNumberOfPlantCards(0),
	m_iNumberOfCitiesPoweredThisTurn(0) {

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
		ResourceMarketBuyResource(RESOURCE_COAL);
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
		ResourceMarketBuyResource(RESOURCE_OIL);
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
		ResourceMarketBuyResource(RESOURCE_GARBAGE);
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
		ResourceMarketBuyResource(RESOURCE_URANIUM);
		m_iMoney -= iUraniumPrice;
		m_iUranium++;

		std::cout << "#Bought_Resource_Uranium\n";

		return BUY_BOUGHT;
	}
}

BuyResult_e CPlayer::AttemptToBuyPlantCard(CDeck* deck, int cardNumber) {
	CCard card = deck->FindCard(cardNumber);
	int cardPrice = card.GetCost();

	if (GetMoney() < cardPrice) {
		std::cout << "#Not_Enough_Money\n";
		return BUY_CANT_AFFORD;
	}

	else if (cardPrice == 0) {
		std::cout << "#Not_Enough_Resources\n";
		return BUY_CANT_AFFORD;
	}

	else {
		m_iCard[m_iNumberOfPlantCards] = card;
		m_iMoney -= cardPrice;
		m_iNumberOfPlantCards++;

		std::cout << "#Bought_Plant_Card_Number" << cardNumber;
		return BUY_BOUGHT;
	}
}

GenerateResult_e CPlayer::GenerateEletricity(int cardNum) {
	CCard card = m_iCard[cardNum];
	int fuelType = card.GetResources();
	int cost = card.GetCost();
	switch (fuelType) {
		//clean energy
	case 0:
		m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
		return GENERATE_SUCCEED;

		//coal
	case 1:
		if (m_iCoal < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iCoal -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}

		//oil
	case 2:
		if (m_iOil < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iOil -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}

		//hybrid
	case 3:
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

		//garbage
	case 4:
		if (m_iGarbage < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iGarbage -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}

		//uranium
	case 8:
		if (m_iUranium < cost)
			return GENERATE_NOT_ENOUGH_RESOURCE;
		else {
			m_iUranium -= cost;
			m_iNumberOfCitiesPoweredThisTurn += card.GetCitiesPowered();
			return GENERATE_SUCCEED;
		}
	}

}