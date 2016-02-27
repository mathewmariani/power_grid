#include "CResourceMarket.h"

short g_iCoalCount = STARTING_COAL;
short g_iOilCount = STARTING_OIL;
short g_iGarbageCount = STARTING_GARBAGE;
short g_iUraniumCount = STARTING_URANIUM;

void ResourceMarketBuyResource(ResourceType_e resource) {
	switch (resource) {
	case RESOURCE_COAL:
		g_iCoalCount--;
		break;
	case RESOURCE_OIL:
		g_iOilCount--;
		break;
	case RESOURCE_GARBAGE:
		g_iGarbageCount--;
		break;
	case RESOURCE_URANIUM:
		g_iUraniumCount--;
		break;
	default:
		break;
	}
}

void ResourceMarketSellResource(ResourceType_e resource) {
	switch (resource) {
	case RESOURCE_COAL:
		g_iCoalCount++;
		break;
	case RESOURCE_OIL:
		g_iOilCount++;
		break;
	case RESOURCE_GARBAGE:
		g_iGarbageCount++;
		break;
	case RESOURCE_URANIUM:
		g_iUraniumCount++;
		break;
	default:
		break;
	}
}

void PrintResourceMarket() {
	std::cout << "==============================" << "\n";
	std::cout << "RESOURCE MARKET\n";

	std::cout << "COAL\n";
	std::cout << "QUANT.:\t\t" << g_iCoalCount << "\n";
	std::cout << "PRICE:\t\t" << CostOfCoal() << "\n\n";

	std::cout << "OIL\n";
	std::cout << "QUANT.:\t\t" << g_iOilCount << "\n";
	std::cout << "PRICE:\t\t" << CostOfOil() << "\n\n";

	std::cout << "GARBAGE\n";
	std::cout << "QUANT.:\t\t" << g_iGarbageCount << "\n";
	std::cout << "PRICE:\t\t" << CostOfGarbage() << "\n\n";

	std::cout << "URANIUM\n";
	std::cout << "QUANT.:\t\t" << g_iUraniumCount << "\n";
	std::cout << "PRICE:\t\t" << CostOfUranium() << "\n\n";
	std::cout << "==============================" << "\n";
}