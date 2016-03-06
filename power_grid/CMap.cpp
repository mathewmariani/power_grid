#include "CMap.h"

CMap::CMap() {
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("map.xml");
	pugi::xml_node root = doc.child("map");

	// MAT: note for myself and andres
	// basically the algo here is
	// 1. enter the map node
	// 2. loop through all city nodes (children of map)
	// 3. for each city, loop through neighbour nodes (children of city)
	// 4. ezpz O(n^2) you can recursion this for less
	
	for (pugi::xml_node city = root.first_child(); city; city = city.next_sibling()) {
		m_vCities.push_back(CCity(
			XMLParseString(city.attribute("name")),
			XMLParseString(city.attribute("region"))
			));
		
		for (pugi::xml_node neighbour = city.first_child(); neighbour; neighbour = neighbour.next_sibling()) {
			// MAT: since push_back adds an element at the end
			// we can use vector.back() to get the element we just added
			m_vCities.back().AddNeighbour(
				XMLParseString(neighbour.attribute("name")),
				XMLParseInt(neighbour.attribute("cost"))
				);
		}
	}
}

CMap::~CMap() {

}
