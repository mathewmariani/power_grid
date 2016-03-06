#pragma once

#include "IObservable.h"

class ISubject {
public:
	virtual void Attach(IObservable *observable) = 0;
	virtual void Detach(IObservable *observable) = 0;

	template <class T>
	virtual void Notify(T value) = 0;
};