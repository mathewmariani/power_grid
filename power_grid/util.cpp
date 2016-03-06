#include "util.h"

bool XMLParseBool(const pugi::xml_attribute &node) {
	return node.as_bool();
}

double XMLParseDouble(const pugi::xml_attribute &node) {
	return node.as_double();
}

float XMLParseFloat(const pugi::xml_attribute &node) {
	return node.as_float();
}

int XMLParseInt(const pugi::xml_attribute &node) {
	return node.as_int();
}

std::string XMLParseString(const pugi::xml_attribute &node) {
	return node.as_string();
}

pugi::xml_node XMLAppendChild(pugi::xml_node &node, std::string name) {
	return node.append_child(name.c_str());
}