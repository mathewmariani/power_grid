#include "CHouse.h"

CHouse::CHouse(CCity city) : m_City(city) {
	m_City.IncreaseCount();
}

CHouse::~CHouse() {

}

std::string CHouse::GetCity(){
	return m_City.GetName();
}
int	CHouse::getCost(){
	return m_City.GetCost();
}

void CHouse::Serialize(pugi::xml_node &parent) {
	auto house = XMLAppendChild(parent, "house");
	XMLAppendAttribute(house, "city", m_City.GetName());
	XMLAppendAttribute(house, "player", m_Player.GetName());

}
std::string CHouse::BelongsTo() {
	return m_Player.GetName();
}
