#pragma once

#include "CCityData.h"

class CHouseData {
public:
	CHouseData();
	CHouseData(CCityData* city);
	~CHouseData();

	CCityData* GetCity();
	const CCityData* GetCity() const;

private:
	CCityData* city;
};