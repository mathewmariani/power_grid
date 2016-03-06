#include "CCard.h"

CCard::CCard() :
	m_iNumber(0),
	m_iResourceCost(0),
	m_iResources(0),
	m_iNumberOfCitiesPowered(0) {

}

CCard::CCard(int number, int cost, int resources, int poweres) :
	m_iNumber(number),
	m_iResourceCost(cost),
	m_iResources(resources),
	m_iNumberOfCitiesPowered(poweres) {

}

CCard::~CCard() {

}

int CCard::GetNumber() {
	return this->m_iNumber;
}

int CCard::GetCost() {
	return this->m_iResourceCost;
}

int CCard::GetResources() {
	return this->m_iResources;
}

int CCard::GetCitiesPowered() {
	return this->m_iNumberOfCitiesPowered;
}

const int CCard::GetNumber() const {
	return this->m_iNumber;
}

const int CCard::GetCost() const {
	return this->m_iResourceCost;
}

// MAT: to access this you need to understand Binary Operations
const int CCard::GetResources() const {
	return this->m_iResources;
}

const int CCard::GetCitiesPowered() const {
	return this->m_iNumberOfCitiesPowered;
}