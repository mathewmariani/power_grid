#include "CMap.h"
#include <fstream>

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

void CMap::Serialize(pugi::xml_node &parent) {
	auto map = XMLAppendChild(parent, "map");
	for (CCity n : m_vCities) {
		auto city = XMLAppendChild(map, "city");
		XMLAppendAttribute(city, "name", n.GetName());
		XMLAppendAttribute(city, "region", n.GetRegion());
		for (auto &m : n.m_vConnections) {
			auto neighbour = XMLAppendChild(city, "neighbours");
			XMLAppendAttribute(neighbour, "name", m.first);
			XMLAppendAttribute(neighbour, "cost", m.second);
		}
	}
}
void CMap::addCity(std::string name, std::string region) {
	m_vCities.push_back(CCity(name, region));
}
/*
void CMap::saveMap() {
	std::ofstream map_file;
	map_file.open("PowerGridMap.xml");

	map_file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
	map_file << "<map>" << std::endl;
	for (auto node : m_vCities) {
		map_file << "\t<city name=" << node.GetName() << " region= " << node.GetRegion() << ">" << std::endl;
		for (const auto &i : node.m_vConnections) {
			map_file << "\t\t<neighbours name= '" << i.first << "' cost= '" << i.second << "'/>" << std::endl;
		}
		map_file << "\t</city>" << std::endl;
	}
	map_file << "</map>" << std::endl;
}

void CMap::addCity(std::string name, std::string region) {
	m_vCities.push_back(CCity(name, region));
}
*/