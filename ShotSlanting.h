#pragma once

#include "ShotBase.h"

class ShotSlanting : public ShotBase
{
public:
	ShotSlanting(){}
	virtual ~ShotSlanting(){}

	//ショット開始
	virtual void start(Vec2 pos);
	// 更新
	virtual void update();

private:
};