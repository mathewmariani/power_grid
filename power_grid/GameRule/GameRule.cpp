#include <iostream>
#include <string>
#include <stdlib.h>
#include "player.h"
#include "GameRule.h"

using namespace std;

class Player_;


GameRule::GameRule()
{
	numberOfPlayers = 4;
	string name;
	int id;
	int numberOfCities;
	int maxOfCardNumber;
	

	for (int i = 0; i < 4; i++) {
		cout << "Type in the information of the number" << i + 1 << " player:";
		cin >> name >> id >> numberOfCities >> maxOfCardNumber;

		player[i].setName(name);
		player[i].setID(id);
		player[i].setNumberOfCities(numberOfCities);
		player[i].setMaxOfCardNumbers(maxOfCardNumber);
	}

}
// at the beginning, we set the random order to every player.
void GameRule:: initializeOrder()
{   
	
	int nTemp;
	int nTran[4];

	for (int i = 0; i < this->numberOfPlayers; i++){
		nTran[i] = i;
	}

	for (int i = 0; i < this->numberOfPlayers; i++){
		nTemp = rand() % (4 - i);
		this->player[i].setOrder(nTran[nTemp]);
		nTran[nTemp] = nTran[4 - 1 - i];
	}

	showOrder();
	
}


//when game is play, the player  who has more number of cities will have the priority. Those who has same number of cities, the player who has the biggest card number will have the priority.
//so I use three ternary operator to achieve this function.
// at the first ternary operator we discuss whose number of cities is more, if i is bigger than j we set order, otherwise , there is two possibility ,1. == 2.< so we go to the second ternary operator.
// in the second ternary we discuss i and j is equal number of cities or not, if i and j have same cities we go to the third ternary operator else it can only be i < j becasue the first ternary operator.
// in the third ternary we discuss if i has more max number plant card than j, because every card is unique and have unique id number so that it can only bigger or smaller.
void GameRule::inGameOrder(){
	
	for (int i = 0; i < 4; i++){
		int order = 3;
		for (int j = 0; j < 4; j++){
			if (i != j){
				if ((this->player[i].getNumberOfCities() > this->player[j].getNumberOfCities()) ? (1) : (this->player[i].getNumberOfCities() == this->player[j].getNumberOfCities() ? ((this->player[i].getMaxOfCardNumbers() > this->player[j].getMaxOfCardNumbers()) ? (1) : (0)) : (0))){
					order--;
				}
			}
		}
		this->player[i].setOrder(order);
	}

	showOrder();

}


void GameRule::reverseGameOrder(){
	int tempArr[4];
	for (int i = 0; i < 4; i++)
		tempArr[i] = this->player[i].getOrder();
	for (int i = 0; i < 4; i++)
		this->player[i].setOrder(tempArr[3 - i]);

	showOrder();
}

void  GameRule::showOrder(){
	
	int order = 0;
	for (int i = 0; i < 4; i++){
		order = this->player[i].getOrder();
		printf("the player %d 's order is: %d \n", i, (order+1));
	}
	printf("\n");
}

/*
int GameRule::IWantSupply(){
	//首先列出玩家所拥有的所有信息 以便玩家心中有数 可以输入想要发电的电厂
	p->displayPlayerInfo();
	int suply = 0;
	int Coal = p->numberOfCoal;
	int Oil = p->numberOfOil;
	int Garbage = p->numberOfGarbage;
	int Uranium = p->numberOfUranium;

	int Tag[3];

	for (int i = 0; i<3; i++){
		Tag[i] = 1;
	}

	cout << "Please input which number of plant_card you want to suply and input exit to finish:\n " << endl;

	while (1){
		if ("exit"){

			break;
		}

		//比如输入的是 1 号 电厂发电；
		p[1]的电厂减去相应的能源消耗；
			Tag[i] = Tag[i] - 1;
		if (Coal<0 || Oil<0 || Garbage<0 || Uranium<0 || Tag[1] < 0){
			cout << "You do not have enough resources to use this plant_card please input it again:\n " << endl;
			return IwantSupply(Player *p);
		}
		suply += p[1]的电厂的供电房屋数量；
			cout << "Please input which number of plant_card you want to suply and input exit to finish:\n " << endl;
	}

	//将Coal,Oil,Garbage,Uranium分别传给p；

	if (suply > p->numberOfHouse){
		suply = numberOfhouse;
	}

	return suply;
}

*/

