#pragma once

#include "base.h"

class CCityData {
public:
	CCityData(std::string name, std::string region);
	~CCityData();

	string GetName();
	const string GetName() const;

	string GetRegion();
	const string GetRegion() const;

private:
	string m_sName;
	string m_sRegion;

	std::unordered_map<string, int> m_vConnections;
};