#pragma once

#include <pugixml.hpp>

class ISerializable {
public:
	virtual ~ISerializable() { }

	virtual void Load(pugi::xml_node &parent) = 0;
	virtual void Serialize(pugi::xml_node &parent) = 0;
};