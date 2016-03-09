#include "CHouse.h"

CHouse::CHouse(CCity city) :
	m_pCity(&city) {
	//m_pCity->IncreaseCount();
}

CHouse::~CHouse() {
	// MAT: have to delete your pointers, you're causing memory leaks
	// m_pOwner = nullptr;
	// delete m_pOwner;

	m_pCity = nullptr;
	delete m_pCity;
}

std::string CHouse::GetCity(){
	return m_pCity->GetName();
}

const std::string CHouse::GetCity() const {
	return m_pCity->GetName();
}

int	CHouse::GetCost(){
	return m_pCity->GetCost();
}

const int CHouse::GetCost() const {
	return m_pCity->GetCost();
}

/* Junan: Serialization of houses is done in the CPlayer, i don't think it is necessary here

void CHouse::Serialize(pugi::xml_node &parent) {
	auto house = XMLAppendChild(parent, "house");
	XMLAppendAttribute(house, "city", m_pCity.GetName());
	XMLAppendAttribute(house, "player", m_pOwner.GetName());

}*/
/*
CPlayer* CHouse::BelongsTo() {
	return &m_pOwner;
}
*/
