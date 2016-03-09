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

	//SortOrder();
	//for (int i = 0; i < m_vPlayers.size(); i++) {
	//	std::cout << i + 1 << ". " << m_vPlayers[i].GetName() << "\n";
	//}
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

void CGame::Save() {
	
	// create save game document
	pugi::xml_document doc;
	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";

	// create game root
	auto root = XMLAppendChild(doc, "game");

	// serialize the map we were playing on
	//auto map = XMLAppendChild(root, "map");
	//XMLAppendAttribute(map, "name", currentMap.GetName());

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

	doc.save_file("data/gamesave.xml");
}

void CGame::Load() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/player/players.xml");

	//load resource market
	pugi::xml_node resource_node = doc.child("resources");
	SetResources(XMLParseInt(resource_node.attribute("coal")),
		XMLParseInt(resource_node.attribute("oil")),
		XMLParseInt(resource_node.attribute("garbage")),
		XMLParseInt(resource_node.attribute("uranium")));


	// load players info
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
