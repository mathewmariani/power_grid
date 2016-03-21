#include "config.h"
#include "base.h"
#include "CGameData.h"

void Config::LoadGame(CGameData *data) {
	// MAT: Load everything from a save file into data
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("data/gamesave.xml");
	pugi::xml_node root = doc.child("game");

	//load resource market
	auto resource_node = root.child("resources");
	//SetResources(XMLParseInt(resource_node.attribute("coal")),
	//	XMLParseInt(resource_node.attribute("oil")),
	//	XMLParseInt(resource_node.attribute("garbage")),
	//	XMLParseInt(resource_node.attribute("uranium")));

	//load decks
	auto deck_node = root.child("power-plants");
	std::vector<CCardData> tempInDeck;
	for (auto card = deck_node.child("in-deck"); card; card = card.next_sibling()) {
		tempInDeck.push_back(CCardData(
			XMLParseInt(card.attribute("number")),
			XMLParseInt(card.attribute("cost")),
			XMLParseInt(card.attribute("payment")),
			XMLParseInt(card.attribute("powers"))
			));
	}

	std::vector<CCardData> tempInMarket;
	for (auto card = deck_node.child("in-market"); card; card = card.next_sibling()) {
		tempInMarket.push_back(CCardData(
			XMLParseInt(card.attribute("number")),
			XMLParseInt(card.attribute("cost")),
			XMLParseInt(card.attribute("payment")),
			XMLParseInt(card.attribute("powers"))
			));
	}

	std::vector<CCardData> tempInHold;
	for (auto card = deck_node.child("in-hold"); card; card = card.next_sibling()) {
		tempInHold.push_back(CCardData(
			XMLParseInt(card.attribute("number")),
			XMLParseInt(card.attribute("cost")),
			XMLParseInt(card.attribute("payment")),
			XMLParseInt(card.attribute("powers"))
			));
	}

	std::vector<CCardData> tempDiscarded;
	for (auto card = deck_node.child("in-discarded"); card; card = card.next_sibling()) {
		tempDiscarded.push_back(CCardData(
			XMLParseInt(card.attribute("number")),
			XMLParseInt(card.attribute("cost")),
			XMLParseInt(card.attribute("payment")),
			XMLParseInt(card.attribute("powers"))
			));
	}

	data->deck.SetDeck(tempInDeck, tempInMarket, tempInHold, tempDiscarded);

	// load players info
	auto player_node = root.child("players");

	for (auto player = player_node.first_child(); player; player = player.next_sibling()) {
		
		//parsing cards
		std::vector<CCardData *> tempCards;
		for (auto card = player.child("card"); card; card = card.next_sibling()) {
			tempCards.push_back(data->deck.FindCardInHold(XMLParseInt(card.attribute("number"))));
		}
		
		data->playerList.push_back(CPlayerData(
			XMLParseString(player.attribute("name")),
			XMLParseInt(player.attribute("money")),
			XMLParseInt(player.attribute("coal")),
			XMLParseInt(player.attribute("oil")),
			XMLParseInt(player.attribute("garbage")),
			XMLParseInt(player.attribute("uranium")),
			tempCards
			));
	}

}

void Config::SaveGame(CGameData *data) {
	// MAT: Save everything from data into a save file

	// create save game document
	pugi::xml_document doc;
	auto declarationNode = doc.append_child(pugi::node_declaration);
	declarationNode.append_attribute("version") = "1.0";

	// create game root
	auto root = XMLAppendChild(doc, "game");

	// serialize the decks
	auto decks = XMLAppendChild(root, "power-plants");
	data->deck.Serialize(decks);

	// serialize the resource market
	auto resources = XMLAppendChild(root, "resources");
	XMLAppendAttribute(resources, "coal", data->market.GetCoal());
	XMLAppendAttribute(resources, "oil", data->market.GetOil());
	XMLAppendAttribute(resources, "garbage", data->market.GetGarbage());
	XMLAppendAttribute(resources, "uranium", data->market.GetUranium());

	// serialize players
	auto players = XMLAppendChild(root, "players");
	for (int i = 0; i < data->playerList.size(); i++) {
		data->playerList[i].Serialize(players);
	}

	doc.save_file("data/gamesave.xml");
}