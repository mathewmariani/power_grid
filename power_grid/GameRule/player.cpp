
#include <stack>
#include <iostream>
#include <String>
#include "player.h"



using namespace std;


Player_::Player_(){

	this->name = "";
	this->id = 0;
	this->money = 0;
	this->order = 0;
	this->numberOfCities = 0;
	this->maxOfCardNumber = 0;

}

Player_::Player_(string nm, int i){

	this->name = nm;
	this->id = i;
	this->money = 50;
	this->order = i;
	this->numberOfCities = 10;
	this->maxOfCardNumber = 10;

}

Player_::Player_(string nm, int i, int nfc, int moc){

	 this->name = nm;
	 this->id = i;
	 this->money = 50;
	 this->order = i;
	 this->numberOfCities = nfc;
	 this->maxOfCardNumber = moc;
}

int Player_::getID(){
	return id;
}

void Player_::setID(int id){
	this->id = id;
}

string Player_::getName(){
	return name;
}

void Player_::setName(string name){
	this->name = name;
}

int Player_::getNumberOfCities(){
	return numberOfCities;
}

void Player_::setNumberOfCities(int num){
	this->numberOfCities = num;
}

int Player_::getOrder(){
	return order;
}

void Player_::setOrder(int od){
	this->order = od;
}

int Player_::getMaxOfCardNumbers(){
	return maxOfCardNumber;
}

void Player_::setMaxOfCardNumbers(int maxOfCardNumber){
	this->maxOfCardNumber = maxOfCardNumber;
}

// plantCardSuply is the sum of the suply  that all the plant card that user choose to suply
int Player_::MaxOfPowerSuply(int plantCardSuply){
	int suply = plantCardSuply;
	if (suply > this->getNumberOfCities()){
		suply = this->getNumberOfCities();
	}
	return suply;
}

void Player_::EarnMoney(int suply){

	switch (suply){

	case 0:
		this->money += 10;
		break;

	case 1:
		this->money += 22;
		break;

	case 2:
		this->money += 33;
		break;

	case 3:
		this->money += 44;
		break;

	case 4:
		this->money += 54;
		break;

	case 5:
		this->money += 64;
		break;

	case 6:
		this->money += 73;
		break;

	case 7:
		this->money += 82;
		break;

	case 8:
		this->money += 90;
		break;

	case 9:
		this->money += 98;
		break;

	case 10:
		this->money += 105;
		break;

	case 11:
		this->money += 112;
		break;

	case 12:
		this->money += 118;
		break;

	case 13:
		this->money += 124;
		break;

	case 14:
		this->money += 129;
		break;

	case 15:
		this->money += 134;
		break;

	case 16:
		this->money += 138;
		break;

	case 17:
		this->money += 142;
		break;

	case 18:
		this->money += 145;
		break;

	case 19:
		this->money += 148;
		break;

	case 20:
		this->money += 150;
		break;

	default:
		break;
	}
}