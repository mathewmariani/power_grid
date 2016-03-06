#include "CGame.h"

CGame::CGame() {

}

CGame::~CGame() {

}

// MAT: Everything here is just for testing
void CGame::Initialize() {
	std::cout << "How many players will be playing? ";
	std::cin >> m_iNumberOfPlayers;

	//Phase 1: initialization part
	InitializePlayers();
	InitializeBoard();
	InitializeDeck();

	// Testing part
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

	m_vPlayers[0].AttemptToBuyCard(&deck, 3);
	m_vPlayers[1].AttemptToBuyCard(&deck, 4);
	// End of testing part


	while (true /* by the time the number of a player's house reaches 17, game is over*/) {
		
		//phase 2: Bidding plant cards
		//phase 3: Purchasing resources
		//phase 4: Builing houses
		//phase 5: Power the plants and gain income
	}
}

int CGame::NumberOfPlayers() {
	return m_iNumberOfPlayers;
}

const int CGame::NumberOfPlayers() const {
	return m_iNumberOfPlayers;
}

GameState_e CGame::CurrentState() {
	return STATE_PLACEHOLDER_ONE;
}

const GameState_e CGame::CurrentState() const {
	return STATE_PLACEHOLDER_ONE;
}

void CGame::InitializePlayers() {
	for (int i = 0; i < m_iNumberOfPlayers; i++) {
		std::string temp;
		std::cout << "What is player " << (i + 1) << "'s name? ";
		std::cin >> temp;

		m_vPlayers.push_back(CPlayer(temp));
	}

	//randomize the order in the beginning
	std::random_shuffle(m_vPlayers.begin(), m_vPlayers.end());
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

	// MAT: Added new utility functions for cleaning up XML parsing
	for (int i = 0; i < NumberOfPlayers(); i++) {
		auto tempPlayer = XMLAppendChild(root, "player");
		XMLAppendAttribute(tempPlayer, "name", m_vPlayers[i].GetName());
		XMLAppendAttribute(tempPlayer, "money", m_vPlayers[i].GetMoney());
		XMLAppendAttribute(tempPlayer, "coal", m_vPlayers[i].GetCoal());
		XMLAppendAttribute(tempPlayer, "oil", m_vPlayers[i].GetOil());
		XMLAppendAttribute(tempPlayer, "garbage", m_vPlayers[i].GetGarbage());
		XMLAppendAttribute(tempPlayer, "uranium", m_vPlayers[i].GetUranium());

		for (int j = 0; j < m_vPlayers[i].GetCard().size(); j++) {
			auto tempCard = XMLAppendChild(tempPlayer, "card");
			XMLAppendAttribute(tempCard, "number", m_vPlayers[i].GetCard()[j].GetNumber());
			XMLAppendAttribute(tempCard, "cost", m_vPlayers[i].GetCard()[j].GetCost());
			XMLAppendAttribute(tempCard, "payment", m_vPlayers[i].GetCard()[j].GetResources());
			XMLAppendAttribute(tempCard, "powers", m_vPlayers[i].GetCard()[j].GetCitiesPowered());
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

bool CGame::CompareFunction(const CPlayer &p1, const CPlayer &p2) {
	if (p1.GetHouse().size() > p2.GetHouse().size()) {
		return true;
	} else if (p1.GetHouse().size() == p1.GetHouse().size()) {
		if (p1.GetMaxCardNum() > p2.GetMaxCardNum()) {
			return true;
		}
	}

	return false;
}

void CGame::SortOrder() {
	// error C3867 : 'CGame::CompareFunction' : non - standard syntax; use '&' to create a pointer to member
	// error C2672 : 'sort' : no matching overloaded function found
	// error C2780 : 'void std::sort(_RanIt,_RanIt)' : expects 2 arguments - 3 provided
	//sort(m_vPlayers.begin(), m_vPlayers.end(), CompareFunction);
}


