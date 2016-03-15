#pragma once

// MAT: Forward decleration... hmm
class CStateMachine;

class IState {
public:
	void Initialize(CStateMachine *pOwner) {
		if (pOwner != nullptr) {
			m_pOwner = pOwner;
		}
	}

	virtual void Enter() = 0;
	virtual void Exit() = 0;

private:
	CStateMachine *m_pOwner;
};