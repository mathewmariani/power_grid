#include "CMarket.h"
#include "shareddef.h"

CMarket::CMarket() :
	CMarket(
		STARTING_COAL,
		STARTING_OIL,
		STARTING_GARBAGE, 
		STARTING_URANIUM
		) {

}

CMarket::CMarket(int coal, int oil, int garbage, int uranium) :
	m_iCoal(coal),
	m_iOil(oil),
	m_iGarbage(garbage),
	m_iUranium(uranium) {

}

CMarket::~CMarket() {

}

int CMarket::GetCoal() {
	return m_iCoal;
}

const int CMarket::GetCoal() const {
	return m_iCoal;
}

BuyResults_e CMarket::AttemptToBuyCoal() {
	if (m_iCoal == 0) {
		return BUY_NOT_ENOUGH_RESOURCE;
	} else {
		--m_iCoal;
		Notify();
		return BUY_SUCCEED;
	}
}

int CMarket::GetOil() {
	return m_iOil;
}

const int CMarket::GetOil() const {
	return m_iOil;
}

BuyResults_e CMarket::AttemptToBuyOil() {
	if (m_iCoal == 0) {
		return BUY_NOT_ENOUGH_RESOURCE;
	}
	else {
		--m_iOil;
		Notify();
		return BUY_SUCCEED;
	}

}

int CMarket::GetGarbage() {
	return m_iGarbage;
}

const int CMarket::GetGarbage() const {
	return m_iGarbage;
}

BuyResults_e CMarket::AttemptToBuyGarbage() {
	if (m_iGarbage == 0) {
		return BUY_NOT_ENOUGH_RESOURCE;
	}
	else {
		--m_iGarbage;
		Notify();
		return BUY_SUCCEED;
	}
}

int CMarket::GetUranium() {
	return m_iUranium;
}

const int CMarket::GetUranium() const {
	return m_iUranium;
}

BuyResults_e CMarket::AttemptToBuyUranium() {
	if (m_iUranium == 0) {
		return BUY_NOT_ENOUGH_RESOURCE;
	}
	else {
		--m_iUranium;
		Notify();
		return BUY_SUCCEED;
	}
}

int CMarket::GetCostOfCoal() {
	return (int)(9 - (m_iCoal + 2) / 3);
}

const int CMarket::GetCostOfCoal() const {
	return (int)(9 - (m_iCoal + 2) / 3);
}

int CMarket::GetCostOfOil() {
	return (int)(9 - (m_iOil + 2) / 3);
}

const int CMarket::GetCostOfOil() const {
	return (int)(9 - (m_iOil + 2) / 3);
}

int CMarket::GetCostOfGarbage() {
	return (int)(9 - (m_iGarbage + 2) / 3);
}

const int CMarket::GetCostOfGarbage() const {
	return (int)(9 - (m_iGarbage + 2) / 3);
}

int CMarket::GetCostOfUranium() {
	return (int)(18 - m_iUranium * 2);
}

const int CMarket::GetCostOfUranium() const {
	return (int)(18 - m_iUranium * 2);
}
