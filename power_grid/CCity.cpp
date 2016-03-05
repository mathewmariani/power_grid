#include "CCity.h"

CCity::CCity() :
	m_sName("") {

}

CCity::CCity(std::string name) :
	m_sName(name) {

}

CCity::~CCity() {

}

std::string CCity::GetName() {
	return this->m_sName;
}