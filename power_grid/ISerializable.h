#pragma once

#include <pugixml.hpp>

class ISerializable {
public:
	virtual void Serialize(pugi::xml_node &parent) = 0;
};