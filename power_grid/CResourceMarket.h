#pragma once

#include "base.h"
#include "shareddef.h"

// I chose to make the resource market a collection of
// global variables and functions rather than a function
// due to the simplicity that the resource market is just
// a collection of numbers that can be derived mathematically

enum ResourceType_e {
	RESOURCE_NONE = 0,
	RESOURCE_COAL = (1 << 1),
	RESOURCE_OIL = (1 << 2),
	RESOURCE_GARBAGE = (1 << 3),
	RESOURCE_URANIUM = (1 << 4),
};

void ResourceMarketSellResource(ResourceType_e resource);
void PrintResourceMarket();

void SetResources(int coal, int oil, int garbage, int uranium);

extern short g_iCoalCount;
extern short g_iOilCount;
extern short g_iGarbageCount;
extern short g_iUraniumCount;

inline int CostOfCoal() {
	return (int)(9 - (g_iCoalCount + 2) / 3);
}

inline int CostOfOil() {
	return (int)(9 - (g_iOilCount + 2) / 3);
}

inline int CostOfGarbage() {
	return (int)(9 - (g_iGarbageCount + 2) / 3);
}

inline int CostOfUranium() {
	return (int)(18 - g_iUraniumCount * 2);
}