#pragma once

class CGameController;

class IState {
public:
	void Initialize(CGameController *pOwner) {
		if (pOwner != nullptr) {
			m_pOwner = pOwner;
		}
	}
	virtual void Start() = 0;
	virtual void Enter() = 0;
	virtual void Exit() = 0;

	CGameController *m_pOwner;
};