#pragma once

class IObservable {
public:
	template <class T>
	virtual void Update(T value) = 0;
};