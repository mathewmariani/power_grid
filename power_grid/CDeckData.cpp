#include "CDeckData.h"

//Junan: According to the rule, first 8 cards(number from 3 to 10) are put into the market, 
//       and then pick out the card number 13, shuffle all other cards, remove some cards
//       (Here I have 2 versions, 1 is to remove 8 cards, the other is to remove n cards, n
//       is the number of players. I use first version for now.), put the 13 card to the top
//       of the deck. 
//       I used a trick in the deck.xml to make it easier to implement: put the node of card 13
//       right after the card 10, such that to make sure the first card in the deck is 13. And 
//       then shuffle all the remaining cards in the deck.
//       And since the deck is already randomized, so I simply discard the last 8 cards
CDeckData::CDeckData() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("deck.xml");

	pugi::xml_node cardTemp = doc.child("deck").first_child();

	//put the first 8 cards into the market
	for (int i = 0; i < 8; i++) {
		m_vInMarket.push_back(CCardData(
			XMLParseInt(cardTemp.attribute("number")),
			XMLParseInt(cardTemp.attribute("cost")),
			XMLParseInt(cardTemp.attribute("payment")),
			XMLParseInt(cardTemp.attribute("powers"))
			));
		cardTemp = cardTemp.next_sibling();
	}

	//put the remaining cards in the deck
	for (; cardTemp; cardTemp = cardTemp.next_sibling()) {
		m_vInDeck.push_back(CCardData(
			XMLParseInt(cardTemp.attribute("number")),
			XMLParseInt(cardTemp.attribute("cost")),
			XMLParseInt(cardTemp.attribute("payment")),
			XMLParseInt(cardTemp.attribute("powers"))
			));
	}

	//shuffle the deck except card 13, so that card 13 is still on the top of the deck
	std::random_shuffle(m_vInDeck.begin() + 1, m_vInDeck.end());

	//remove last 8 cards and put them in the discarded deck
	for (int i = 0; i < 8; i++) {
		m_vDiscarded.push_back(m_vInDeck.back());
		m_vInDeck.pop_back();
	}
}


void CDeckData::SetDeck(std::vector<CCardData> deck1, std::vector<CCardData> deck2, std::vector<CCardData> deck3, std::vector<CCardData> deck4) {
	m_vInDeck = deck1;
	m_vInMarket = deck2;
	m_vInHold = deck3;
	m_vDiscarded = deck4;
}


CDeckData::~CDeckData() {

}

// Junan: It is called when a player buys the card with specific number from the market.
//        Basically, it is devided in 2 parts: First, it removes the corresponding card
//        from the market vector. Second, it removes the first card from the deck vector,
//        and insert it into the right position of the market vector.
void CDeckData::PlayerBuysCard(int number) {
	for (int i = 0; i < m_vInMarket.size(); i++) {
		if (number == m_vInMarket[i].GetNumber()) {
			m_vInHold.push_back(m_vInMarket[i]);
			m_vInMarket.erase(m_vInMarket.begin() + i);
			break;
		}
	}

	auto card = m_vInDeck[0];
	m_vInDeck.erase(m_vInDeck.begin());
	int pos = 0;
	for (int i = 0; i < m_vInMarket.size(); i++) {
		if (m_vInMarket[i].GetNumber() < card.GetNumber())
			pos++;
		else
			break;
	}
	m_vInMarket.insert(m_vInMarket.begin() + pos, card);
}


// Junan: It is called when no player buys a card in the Auction phase.
//        Then the market will remove the smallest card and fill in with another card from the
//        top of the deck.
//        It has 2 parts: first, it removes the smallest card from the market vector, and put
//        it into the discarded vector. Second, it it removes the first card from the deck vector,
//        and insert it into the right position of the market vector.
void CDeckData::FillInMarket() {
	m_vDiscarded.push_back(m_vInMarket[0]);
	m_vInMarket.erase(m_vInMarket.begin());

	auto card = m_vInDeck[0];
	m_vInDeck.erase(m_vInDeck.begin());
	int pos = 0;
	for (int i = 0; i < m_vInMarket.size(); i++) {
		if (m_vInMarket[i].GetNumber() < card.GetNumber())
			pos++;
		else
			break;
	}
	m_vInMarket.insert(m_vInMarket.begin() + pos, card);
}


CCardData *CDeckData::FindCardInHold(int number) {
	for (int i = 0; i < m_vInHold.size(); i++) {
		if (m_vInHold[i].GetNumber() == number)
			return &m_vInHold[i];
	}
}

void CDeckData::Serialize(pugi::xml_node &parent) {
	auto inDeck = XMLAppendChild(parent, "in-deck");
	for (int i = 0; i < m_vInDeck.size(); i++) {
		auto card = XMLAppendChild(inDeck, "card");
		XMLAppendAttribute(card, "number", m_vInDeck[i].GetNumber());
		XMLAppendAttribute(card, "cost", m_vInDeck[i].GetCost());
		XMLAppendAttribute(card, "payment", m_vInDeck[i].GetResources());
		XMLAppendAttribute(card, "powers", m_vInDeck[i].GetCitiesPowered());
	}

	auto inMarket = XMLAppendChild(parent, "in-market");
	for (int i = 0; i < m_vInMarket.size(); i++) {
		auto card = XMLAppendChild(inMarket, "card");
		XMLAppendAttribute(card, "number", m_vInMarket[i].GetNumber());
		XMLAppendAttribute(card, "cost", m_vInMarket[i].GetCost());
		XMLAppendAttribute(card, "payment", m_vInMarket[i].GetResources());
		XMLAppendAttribute(card, "powers", m_vInMarket[i].GetCitiesPowered());
	}

	auto inHold = XMLAppendChild(parent, "in-hold");
	for (int i = 0; i < m_vInHold.size(); i++) {
		auto card = XMLAppendChild(inHold, "card");
		XMLAppendAttribute(card, "number", m_vInHold[i].GetNumber());
		XMLAppendAttribute(card, "cost", m_vInHold[i].GetCost());
		XMLAppendAttribute(card, "payment", m_vInHold[i].GetResources());
		XMLAppendAttribute(card, "powers", m_vInHold[i].GetCitiesPowered());
	}

	auto inDiscarded = XMLAppendChild(parent, "in-discarded");
	for (int i = 0; i < m_vDiscarded.size(); i++) {
		auto card = XMLAppendChild(inDiscarded, "card");
		XMLAppendAttribute(card, "number", m_vDiscarded[i].GetNumber());
		XMLAppendAttribute(card, "cost", m_vDiscarded[i].GetCost());
		XMLAppendAttribute(card, "payment", m_vDiscarded[i].GetResources());
		XMLAppendAttribute(card, "powers", m_vDiscarded[i].GetCitiesPowered());
	}
}