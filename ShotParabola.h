#pragma once

#include "ShotBase.h"

class ShotParabola : public ShotBase
{
public:
	ShotParabola(){}
	virtual ~ShotParabola(){}

	//�V���b�g�J�n
	virtual void start(Vec2 pos);
	// �X�V
	virtual void update();
private:
};