#include "CDeck.h"

CDeck::CDeck() :
	m_iCurrentCard(0) {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("deck.xml");
	pugi::xml_node deck_node = doc.child("deck");

	for (pugi::xml_node card = deck_node.first_child(); card; card = card.next_sibling()) {
		m_vDeck.push_back(CCard(
			XMLParseInt(card.attribute("number")),
			XMLParseInt(card.attribute("cost")),
			XMLParseInt(card.attribute("payement")),
			XMLParseInt(card.attribute("powers"))
			));
	}

	std::random_shuffle(m_vDeck.begin(), m_vDeck.end());
}

CDeck::~CDeck() {

}

CCard CDeck::Draw() {
	if (m_vDeck.size() == 0) {
		std::cout << "!!! ERROR: Deck is empty.";
		CCard card;
		return card;
	}

	auto temp = m_vDeck[m_iCurrentCard];
	m_iCurrentCard++;
	return temp;
}