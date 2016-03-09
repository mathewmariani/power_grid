#pragma once

#include "CCity.h"
#include "base.h"

class CHouse {
public:
	CHouse(CCity city);
	~CHouse();

	std::string GetCity();
	const std::string GetCity() const;
	
	int	GetCost();
	const int GetCost() const;

	//also, BelongsTo is unnecesary
	//std::string BelongsTo();
	//void Serialize(pugi::xml_node &parent);

private:
	CCity* m_pCity;
	//Junan: I don't think player is needed here. Actually, we can access houses by players, but not the way around
	//CPlayer* m_Player;
};