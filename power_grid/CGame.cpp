#include "CGame.h"

CGame::CGame() {

}

CGame::~CGame() {

}

// MAT: Everything here is just for testing
void CGame::Initialize() {
	//saving test
	std::cout << "How many players will be playing? ";
	std::cin >> m_iNumberOfPlayers;

	//Phase 1: initialization part
	InitializePlayers();
	InitializeBoard();
	InitializeDeck();
	InitializeMap();

	//Sorting the order of action
	SortOrder();

	// Auction power plant
	for (int i = 0; i < m_vPlayers.size(); i++) {
		m_vPlayers[i].AttemptToBuyCard(&m_Deck, i + 3);
	}

	// Buying resources, reverse order
	for (int i = m_vPlayers.size() - 1; i >= 0; i--) {
		m_vPlayers[i].AttemptToBuyCoal();
		m_vPlayers[i].AttemptToBuyOil();
		m_vPlayers[i].AttemptToBuyGarbage();
		m_vPlayers[i].AttemptToBuyUranium();
	}
	
	// building phase, reverse order
	// error generated, so abandon this part for now
	/*for (int i = m_vPlayers.size() - 1; i >= 0; i--) {
		CCity city = m_Map.GetCityByName("Calgary");
		m_vPlayers[i].BuildHouseOn(city);
	}*/

	// Adding cities
	m_Map.AddCity("Gotham", "Whatever");
	m_Map.AddCity("Montreal", "Quebec");



	Save();


	/*
	//Loading test
	Load();

	std::cout << "Players have been loaded! There are " << m_vPlayers.size() << " players.\n";
	for (int i = 0; i < m_vPlayers.size(); i++) {
		m_vPlayers[i].Print();
	}
	std::cout << "Resource market has been loaded!\n";
	PrintResourceMarket();

	*/
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
	std::cout << "Players have been created! There are " << m_vPlayers.size() << " players.\n";
	for (int i = 0; i < m_vPlayers.size(); i++) {
		m_vPlayers[i].Print();
	}
}

void CGame::InitializeBoard() {
	std::cout << "Game board has been created!\n";
}

void CGame::InitializeDeck() {
	std::cout << "Plant card deck has been created!\n";
}

void CGame::InitializeMap() {
	std::cout << "Map has been created!\n";
	m_Map.Print();
}

void CGame::Save() {
	
	// create save game document
	pugi::xml_document doc;
	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";

	// create game root
	auto root = XMLAppendChild(doc, "game");

	// serialize the resource market
	auto resources = XMLAppendChild(root, "resources");
	XMLAppendAttribute(resources, "coal", g_iCoalCount);
	XMLAppendAttribute(resources, "oil", g_iOilCount);
	XMLAppendAttribute(resources, "garbage", g_iGarbageCount);
	XMLAppendAttribute(resources, "uranium", g_iUraniumCount);

	// serialize players
	auto players = XMLAppendChild(root, "players");
	for (int i = 0; i < NumberOfPlayers(); i++) {
		m_vPlayers[i].Serialize(players);
	}

	// serialize map
	auto map = XMLAppendChild(root, "map");
	m_Map.Serialize(map);


	doc.save_file("data/gamesave.xml");

	std::cout << "Game saved!\n";
}

void CGame::Load() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/gamesave.xml");
	pugi::xml_node game = doc.child("game");

	//load resource market
	pugi::xml_node resource_node = game.child("resources");
	SetResources(XMLParseInt(resource_node.attribute("coal")),
		XMLParseInt(resource_node.attribute("oil")),
		XMLParseInt(resource_node.attribute("garbage")),
		XMLParseInt(resource_node.attribute("uranium")));


	// load players info
	pugi::xml_node player_node = game.child("players");

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


void CGame::SortOrder() {
	std::sort(m_vPlayers.begin(), m_vPlayers.end(), CompareFunction);
}

bool CompareFunction(const CPlayer &p1, const CPlayer &p2) {
	if (p1.GetHouse().size() > p2.GetHouse().size()) {
		return true;
	}
	else if (p1.GetHouse().size() == p1.GetHouse().size()) {
		if (p1.GetMaxCardNum() > p2.GetMaxCardNum()) {
			return true;
		}
	}

	return false;
}
