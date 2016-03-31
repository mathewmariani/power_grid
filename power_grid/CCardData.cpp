#include "CCardData.h"

CCardData::CCardData() :
	m_iNumber(0),
	m_iResourceCost(0),
	m_iResources(0),
	m_iNumberOfCitiesPowered(0) {

}

CCardData::CCardData(int number, int cost, int resources, int poweres) :
	m_iNumber(number),
	m_iResourceCost(cost),
	m_iResources(resources),
	m_iNumberOfCitiesPowered(poweres) {

}

CCardData::~CCardData() {

}

int CCardData::GetNumber() {
	return this->m_iNumber;
}

const int CCardData::GetNumber() const {
	return this->m_iNumber;
}

int CCardData::GetCost() {
	return this->m_iResourceCost;
}

const int CCardData::GetCost() const {
	return this->m_iResourceCost;
}

int CCardData::GetResources() {
	return this->m_iResources;
}

const int CCardData::GetResources() const {
	return this->m_iResources;
}

int CCardData::GetCitiesPowered() {
	return this->m_iNumberOfCitiesPowered;
}

const int CCardData::GetCitiesPowered() const {
	return this->m_iNumberOfCitiesPowered;
}

void CCardData::Print() {
	std::cout << "Number: " << m_iNumber << "\n";
	std::cout << "Cost: " << m_iResourceCost << "\n";
	std::cout << "Resource: " << m_iResources << "\n";
	std::cout << "Powers: " << m_iNumberOfCitiesPowered << "\n";
	std::cout << "----------------------\n";
}
