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

	for (int i = 0; i < 8; i++) {
		m_vInMarket.push_back(CCardData(
			XMLParseInt(cardTemp.attribute("number")),
			XMLParseInt(cardTemp.attribute("cost")),
			XMLParseInt(cardTemp.attribute("payment")),
			XMLParseInt(cardTemp.attribute("powers"))
			));
		cardTemp = cardTemp.next_sibling();
	}

	for (; cardTemp; cardTemp = cardTemp.next_sibling()) {
		m_vInDeck.push_back(CCardData(
			XMLParseInt(cardTemp.attribute("number")),
			XMLParseInt(cardTemp.attribute("cost")),
			XMLParseInt(cardTemp.attribute("payment")),
			XMLParseInt(cardTemp.attribute("powers"))
			));
	}

	std::random_shuffle(m_vInDeck.begin() + 1, m_vInDeck.end());

	for (int i = 0; i < 8; i++) {
		m_vInDeck.pop_back();
	}
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
			m_vInPlayer.push_back(m_vInMarket[i]);
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