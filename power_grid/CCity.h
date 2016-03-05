#pragma once

#include "base.h"

class CCity {
public:
	CCity();
	CCity(std::string name);
	~CCity();

	std::string GetName();
private:
	std::string m_sName;

	const int m_iBasePrice = 10;
};