#include "CHouseData.h"

CHouseData::CHouseData() :
	city(NULL){

}

CHouseData::CHouseData(CCityData* city) :
	city(city) {
	city->IncreaseCount();
}

CHouseData::~CHouseData() {
	delete city;
	city = NULL;
}

CCityData* CHouseData::GetCity() {
	return city;
}

const CCityData* CHouseData::GetCity() const{
	return city;
}