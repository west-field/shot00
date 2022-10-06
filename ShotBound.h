#pragma once

#include "ShotBase.h"

class ShotBound : public ShotBase
{
public:
	ShotBound() { m_boundCount = 0; }
	virtual ~ShotBound() {}

	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();	//update() = 0;	���S���z�֐��ɂ���̂�ok

private:
	//���˕Ԃ�����
	int m_boundCount;
};