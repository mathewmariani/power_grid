#pragma once

#include <pugixml.hpp>

extern bool XMLParseBool(const pugi::xml_attribute &node);
extern double XMLParseDouble(const pugi::xml_attribute &node);
extern float XMLParseFloat(const pugi::xml_attribute &node);
extern int XMLParseInt(const pugi::xml_attribute &node);
extern std::string XMLParseString(const pugi::xml_attribute &node);
extern pugi::xml_node XMLAppendChild(pugi::xml_node &node, std::string name);


extern pugi::xml_node XMLAppendChild(pugi::xml_document &doc, std::string name);

//template<class T>
//inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, T value) {
//	node.append_attribute(name.c_str()) = value;
//}

inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, bool value) {
	node.append_attribute(name.c_str()) = value;
}

inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, double value) {
	node.append_attribute(name.c_str()) = value;
}

inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, float value) {
	node.append_attribute(name.c_str()) = value;
}

inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, int value) {
	node.append_attribute(name.c_str()) = value;
}

inline void XMLAppendAttribute(pugi::xml_node &node, std::string name, std::string value) {
	node.append_attribute(name.c_str()) = value.c_str();
}

inline void XMLAppendChild(pugi::xml_node &root, pugi::xml_node &child) {
	root.append_copy(child);
}