#pragma once

#include "base.h"
#include "CCity.h"

class CHouse {
public:
	CHouse(CCity city);
	~CHouse();

private:
	CCity m_City;
};