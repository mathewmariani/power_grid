#include "CPlayer.h"

CPlayer::CPlayer(std::string name) :
	m_sName(name),
	m_iMoney(0),
	m_iCoal(0),
	m_iOil(0),
	m_iGarbage(0),
	m_iUranium(0) {

}

CPlayer::~CPlayer() {

}

std::string CPlayer::GetName() {
	return m_sName;
}

int CPlayer::GetMoney() {
	return m_iMoney;
}

int CPlayer::GetCoal() {
	return m_iCoal;
}

int CPlayer::GetOil() {
	return m_iOil;
}

int CPlayer::GetGarbage() {
	return m_iGarbage;
}

int CPlayer::GetUranium() {
	return m_iUranium;
}

const std::string CPlayer::GetName() const {
	return m_sName;
}

const int CPlayer::GetMoney() const {
	return m_iMoney;
}

const int CPlayer::GetCoal() const {
	return m_iCoal;
}

const int CPlayer::GetOil() const {
	return m_iOil;
}

const int CPlayer::GetGarbage() const {
	return m_iGarbage;
}

const int CPlayer::GetUranium() const {
	return m_iUranium;
}

BuyResult_e CPlayer::AttemptToBuyCoal() {
	return BUY_CANT_AFFORD;
}

BuyResult_e CPlayer::AttemptToBuyOil() {
	return BUY_CANT_AFFORD;
}

BuyResult_e CPlayer::AttemptToBuyGarbage() {
	return BUY_CANT_AFFORD;
}

BuyResult_e CPlayer::AttemptToBuyUranium() {
	return BUY_CANT_AFFORD;
}