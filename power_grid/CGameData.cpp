#include "CGameData.h"

static CGameData _gameData;
CGameData *pGameData = &_gameData;

CGameData::CGameData() :
	currentRound(0),
	currentTime(0.0f) {
	map.LoadMap("map_canada.xml");
}

void CGameData::Print() {
	std::cout << "There are " << playerList.size() << " players:\n";
	for (int i = 0; i < playerList.size(); i++)
		std::cout << i + 1 << ". " << playerList[i].GetName() << "\n";
}

BuyResults_e CGameData::PlayerAttemptsToBuyResource(int playerNum, int resourceType) {
	switch (resourceType)
	{
		//coal
	case 1:
		if (market.GetCoal() == 0) {
			std::cout << "ERROR: THE COAL IS SOLD OUT!\n";
			return BUY_NOT_ENOUGH_RESOURCE;
		}

		else {
			if (playerList[playerNum].GetMoney() < market.GetCostOfCoal()) {
				std::cout << "ERROR: NOT ENOUGH MONEY!\n";
				std::cout << "       YOU HAVE $" << playerList[playerNum].GetMoney() << ", WHILE THE PRICE IS $" << market.GetCostOfCoal() << "\n";
				return BUY_INSUFFICIENT_FUNDS;
			}
			else {
				market.SellCoal();
				playerList[playerNum].BuyCoal();
				playerList[playerNum].ConsumeMoney(market.GetCostOfCoal());
				std::cout << "COAL BOUGHT SUCCEEDED!";
				return BUY_SUCCEED;
			}
		}
		//oil
	case 2:
		if (market.GetOil() == 0) {
			std::cout << "ERROR: THE OIL IS SOLD OUT!\n";
			return BUY_NOT_ENOUGH_RESOURCE;
		}

		else {
			if (playerList[playerNum].GetMoney() < market.GetCostOfOil()) {
				std::cout << "ERROR: NOT ENOUGH MONEY!\n";
				std::cout << "       YOU HAVE $" << playerList[playerNum].GetMoney() << ", WHILE THE PRICE IS $" << market.GetCostOfOil() << "\n";
				return BUY_INSUFFICIENT_FUNDS;
			}
			else {
				market.SellOil();
				playerList[playerNum].BuyOil();
				playerList[playerNum].ConsumeMoney(market.GetCostOfOil());
				std::cout << "OIL BOUGHT SUCCEEDED!";
				return BUY_SUCCEED;
			}
		}
		//garbage
	case 3:
		if (market.GetGarbage() == 0) {
			std::cout << "ERROR: THE GARBAGE IS SOLD OUT!\n";
			return BUY_NOT_ENOUGH_RESOURCE;
		}

		else {
			if (playerList[playerNum].GetMoney() < market.GetCostOfGarbage()) {
				std::cout << "ERROR: NOT ENOUGH MONEY!\n";
				std::cout << "       YOU HAVE $" << playerList[playerNum].GetMoney() << ", WHILE THE PRICE IS $" << market.GetCostOfGarbage() << "\n";
				return BUY_INSUFFICIENT_FUNDS;
			}
			else {
				market.SellGarbage();
				playerList[playerNum].BuyGarbage();
				playerList[playerNum].ConsumeMoney(market.GetCostOfGarbage());
				std::cout << "GARBAGE BOUGHT SUCCEEDED!";
				return BUY_SUCCEED;
			}
		}
		//Uranium
	case 4:
		if (market.GetUranium() == 0) {
			std::cout << "ERROR: THE URANIUM IS SOLD OUT!\n";
			return BUY_NOT_ENOUGH_RESOURCE;
		}

		else {
			if (playerList[playerNum].GetMoney() < market.GetCostOfUranium()) {
				std::cout << "ERROR: NOT ENOUGH MONEY!\n";
				std::cout << "       YOU HAVE $" << playerList[playerNum].GetMoney() << ", WHILE THE PRICE IS $" << market.GetCostOfUranium() << "\n";
				return BUY_INSUFFICIENT_FUNDS;
			}
			else {
				market.SellUranium();
				playerList[playerNum].BuyUranium();
				playerList[playerNum].ConsumeMoney(market.GetCostOfUranium());
				std::cout << "URANIUM BOUGHT SUCCEEDED!";
				return BUY_SUCCEED;
			}
		}
	default:
		break;
	}
}
