#pragma once

#include <pugixml.hpp>

extern bool XMLParseBool(const pugi::xml_attribute &node);
extern double XMLParseDouble(const pugi::xml_attribute &node);
extern float XMLParseFloat(const pugi::xml_attribute &node);
extern int XMLParseInt(const pugi::xml_attribute &node);
extern std::string XMLParseString(const pugi::xml_attribute &node);