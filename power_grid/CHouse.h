#pragma once

#include "base.h"
#include "CCity.h"
#include "ISerializable.h"

class CHouse : ISerializable {
public:
	CHouse(CCity city);
	~CHouse();
	std::string	GetCity();
	int	getCost();
	std::string BelongsTo();
	void Serialize(pugi::xml_node &parent);

private:
	CCity m_City;
	CPlayer m_Player;
};