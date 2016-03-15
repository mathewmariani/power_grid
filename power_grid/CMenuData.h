#pragma once

// Common
#include "ISubject.h"

#include "base.h"

enum MenuSelection_e {
	SELECTION_NONE = 0,
	SELECTION_NEW = (1 << 0),
	SELECTION_LOAD = (1 << 1),
};

class CMenuData : public ISubject {
public:
	CMenuData() {

	};

	~CMenuData() {

	};

	vector<string> GetMenuOptions() {
		return m_sOptions;
	};

	const vector<string> GetMenuOptions() const {
		return m_sOptions;
	};

	MenuSelection_e GetState() {
		return currentState;
	}

	void SelectMenuOption(int value) {
		switch (value) {
		case 1:
			currentState = SELECTION_NEW;
			break;
		case 2:
			currentState = SELECTION_LOAD;
			break;
		default:
			currentState = SELECTION_NONE;
			break;
		}

		Notify();
	}

private:
	MenuSelection_e currentState;
	vector<string> m_sOptions = {
		"Start New Game.",
		"Load Old Game."
	};
};