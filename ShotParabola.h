#pragma once

#include "ShotBase.h"

class ShotParabola : public ShotBase
{
public:
	ShotParabola(){}
	virtual ~ShotParabola(){}

	//ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();
private:
};