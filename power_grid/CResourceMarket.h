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

void ResourceMarketBuyResource(ResourceType_e resource);
void ResourceMarketSellResource(ResourceType_e resource);
void PrintResourceMarket();

extern short g_iCoalCount;
extern short g_iOilCount;
extern short g_iGarbageCount;
extern short g_iUraniumCount;

inline int CostOfCoal() {
	return (int)(floor(9 - (g_iCoalCount / 3)));
}

inline int CostOfOil() {
	return (int)(floor(9 - (g_iOilCount / 3)));
}

inline int CostOfGarbage() {
	return (int)(floor(9 - (g_iGarbageCount / 3)));
}

inline int CostOfUranium() {
	if (g_iUraniumCount == 1) {
		return 16;
	}
	else if (g_iUraniumCount == 2) {
		return 14;
	}
	else if (g_iUraniumCount == 3) {
		return 12;
	}
	else if (g_iUraniumCount == 4) {
		return 10;
	}
	else {
		return (int)(13 - g_iUraniumCount);
	}
}