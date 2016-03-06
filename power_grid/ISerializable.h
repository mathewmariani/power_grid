#pragma once

class ISerializable {
public:
	virtual void Serialize() = 0;
};