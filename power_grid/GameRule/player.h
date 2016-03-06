#pragma once


#include <string>
#include <stdlib.h>


using namespace std;


class Player_{



private:
	string name;
	int id;
	int money;
	int order;
	int numberOfCities;
	int maxOfCardNumber;

public:
	Player_();

	Player_(string nm, int i);

	Player_(string nm, int i, int nfc, int moc);

	int getID();

	void setID(int id);

	string getName();

	void setName(string name);

	int getNumberOfCities();

	void setNumberOfCities(int num);

	int getOrder();

	void setOrder(int od);

	int getMaxOfCardNumbers();

	void setMaxOfCardNumbers(int maxOfCardNumber);

	int MaxOfPowerSuply(int plantCardSuply);

	void EarnMoney(int suply);

	

};

