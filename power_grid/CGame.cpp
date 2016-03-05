#include "CGame.h"

CGame::CGame() {

}

CGame::~CGame() {

}

void CGame::Initialize() {
	std::cout << "How many players will be playing? ";
	std::cin >> m_iNumberOfPlayers;


	InitializePlayers();
	InitializeBoard();
	InitializeDeck();

	// Print Everything we (the driver) has
	PrintResourceMarket();

	// buy some stuff
	m_vPlayers[0].AttemptToBuyCoal();
	m_vPlayers[0].AttemptToBuyOil();
	m_vPlayers[0].AttemptToBuyGarbage();
	m_vPlayers[0].AttemptToBuyUranium();

	// look at all out loot
	m_vPlayers[0].Print();

	// take a look at the market
	PrintResourceMarket();

	// Test the deck
	CDeck deck;
	m_vPlayers[0].AttemptToBuyPlantCard(&deck, 3);
	m_vPlayers[1].AttemptToBuyPlantCard(&deck, 4);
}

int CGame::NumberOfPlayers() {
	return m_iNumberOfPlayers;
}

const int CGame::NumberOfPlayers() const {
	return m_iNumberOfPlayers;
}

int CGame::CurrentPhase() {
	return 0;
}

const int CGame::CurrentPhase() const {
	return 0;
}

void CGame::InitializePlayers() {
	for (int i = 0; i < m_iNumberOfPlayers; i++) {
		std::string temp;
		std::cout << "What is player " << (i+1) << "'s name? ";
		std::cin >> temp;

		m_vPlayers.push_back(CPlayer(temp));
	}
}

void CGame::InitializeBoard() {

}

void CGame::InitializeDeck() {

}

void CGame::SavePlayers() {
	pugi::xml_document doc;

	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";

	auto root = doc.append_child("playerList");

	for (int i = 0; i < NumberOfPlayers(); i++) {
		std::string name = m_vPlayers[i].GetName();
		int money = m_vPlayers[i].GetMoney();
		int coal = m_vPlayers[i].GetCoal();
		int oil = m_vPlayers[i].GetOil();
		int garbage = m_vPlayers[i].GetGarbage();
		int uranium = m_vPlayers[i].GetUranium();
		std::vector<CCard> card = m_vPlayers[i].GetCard();

		auto tempPlayer = root.append_child("player");
		tempPlayer.append_attribute("name") = name.c_str();
		tempPlayer.append_attribute("money") = money;
		tempPlayer.append_attribute("coal") = coal;
		tempPlayer.append_attribute("oil") = oil;
		tempPlayer.append_attribute("garbage") = garbage;
		tempPlayer.append_attribute("uranium") = uranium;

		for (int j = 0; j < card.size(); j++) {
			int number = m_vPlayers[i].GetCard()[j].GetNumber();
			int cost = m_vPlayers[i].GetCard()[j].GetCost();
			int payment = m_vPlayers[i].GetCard()[j].GetResources();
			int powers = m_vPlayers[i].GetCard()[j].GetCitiesPowered();

			auto tempCard = tempPlayer.append_child("card");
			tempCard.append_attribute("number") = number;
			tempCard.append_attribute("cost") = cost;
			tempCard.append_attribute("payment") = payment;
			tempCard.append_attribute("powers") = powers;
		}
	}

	doc.save_file("data/player/players.xml");
}

void CGame::LoadPlayers() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/player/players.xml");
	pugi::xml_node player_node = doc.child("playerList");

	for (pugi::xml_node player = player_node.first_child(); player; player = player.next_sibling()) {

		//parsing cards
		std::vector<CCard> tempCard;
		for (pugi::xml_node card = player.first_child(); card; card = card.next_sibling()) {
			tempCard.push_back(CCard(
				XMLParseInt(card.attribute("number")),
				XMLParseInt(card.attribute("cost")),
				XMLParseInt(card.attribute("payment")),
				XMLParseInt(card.attribute("powers"))
				));
		}

		m_vPlayers.push_back(CPlayer(
			XMLParseString(player.attribute("name")),
			XMLParseInt(player.attribute("money")),
			XMLParseInt(player.attribute("coal")),
			XMLParseInt(player.attribute("oil")),
			XMLParseInt(player.attribute("garbage")),
			XMLParseInt(player.attribute("uranium")),
			tempCard
			));
	}

}

void CGame::LoadPlayers(std::string name) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/player/players.xml");
	pugi::xml_node player_node = doc.child("playerList");

	for (pugi::xml_node player = player_node.first_child(); player; player = player.next_sibling()) {
		if (std::strcmp(XMLParseString(player.attribute("name")).c_str(), name.c_str()) == 0) {
			
			//parsing cards
			std::vector<CCard> tempCard;
			for (pugi::xml_node card = player.first_child(); card; card = card.next_sibling()) {
				tempCard.push_back(CCard(
					XMLParseInt(card.attribute("number")),
					XMLParseInt(card.attribute("cost")),
					XMLParseInt(card.attribute("payment")),
					XMLParseInt(card.attribute("powers"))
					));
			}

			m_vPlayers.push_back(CPlayer(
				XMLParseString(player.attribute("name")),
				XMLParseInt(player.attribute("money")),
				XMLParseInt(player.attribute("coal")),
				XMLParseInt(player.attribute("oil")),
				XMLParseInt(player.attribute("garbage")),
				XMLParseInt(player.attribute("uranium")),
				tempCard
				));
			break;
		}
	}

}
