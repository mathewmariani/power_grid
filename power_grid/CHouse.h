#pragma once

#include "base.h"
#include "CCity.h"
#include "CPlayer.h"

class CHouse {
public:
	CHouse(CCity city);
	~CHouse();
	std::string	GetCity();
	int	getCost();
	//also, BelongsTo is unnecesary
	//std::string BelongsTo();
	//void Serialize(pugi::xml_node &parent);

private:
	CCity* m_City;
	//Junan: I don't think player is needed here. Actually, we can access houses by players, but not the way around
	//CPlayer* m_Player;
};