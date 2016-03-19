#pragma once

class CGameController;

class IState {
public:
	void Initialize(CGameController *pOwner) {
		if (pOwner != nullptr) {
			m_pOwner = pOwner;
		}
	}

	virtual void Enter() = 0;
	virtual void Exit() = 0;

private:
	CGameController *m_pOwner;
};