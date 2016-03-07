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

pugi::xml_node XMLAppendChild(pugi::xml_document &doc, std::string name) {
	pugi::xml_node root = doc.append_child();
	root.set_name(name.c_str());

	return root;
}

pugi::xml_node XMLAppendChild(pugi::xml_node &parent, std::string name) {
	pugi::xml_node child = parent.append_child();
	child.set_name(name.c_str());

	return child;
}
