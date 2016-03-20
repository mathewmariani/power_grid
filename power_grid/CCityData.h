#pragma once

#include "base.h"
#include "ISubject.h"
#include "CHouseData.h"

class CCityData : public ISubject {
public:
	CCityData(std::string name, std::string region);
	~CCityData();

	string GetName();
	const string GetName() const;

	string GetRegion();
	const string GetRegion() const;

	string GetNeighbours();

	void AddNeighbour(string name, int cost);
	
	void AddHouse(CHouseData* house);

	int GetHouses();

private:
	string m_sName;
	string m_sRegion;

	std::unordered_map<string, int> m_vConnections;
	std::vector<CHouseData*> m_vHouses;
};