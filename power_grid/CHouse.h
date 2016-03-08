#pragma once

#include "base.h"
#include "CCity.h"

class CHouse {
public:
	CHouse(CCity city);
	~CHouse();
	std::string	getCity();
	int			getCost();
	std::string belongsTo();

private:
	CCity m_City;
	CPlayer m_Player;

};