#pragma once

#include "ShotBase.h"

class ShotSlanting : public ShotBase
{
public:
	ShotSlanting(){}
	virtual ~ShotSlanting(){}

	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();

private:
};