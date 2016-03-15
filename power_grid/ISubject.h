#pragma once

// common
#include "IObserver.h"

#include "base.h"

class ISubject {
public:
	ISubject() {

	}

	~ISubject() {
		
	}

	void Attach(IObserver* observer) {
		_observers.push_back(observer);

	}

	void Detach(IObserver* observer) {
		_observers.remove(observer);
	}

	void Notify() {
		for (auto i = _observers.begin(); i != _observers.end(); i++) {
			(*i)->Update();
		}
	}

private:
	list<IObserver*> _observers;
};