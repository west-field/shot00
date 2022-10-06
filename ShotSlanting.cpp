#include "game.h"
#include "ShotSlanting.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr float kGravity = 1.0f;

}

//ショット開始
void ShotSlanting::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;
}
// 更新
void ShotSlanting::update()
{
	if (!m_isExist)	return;
	m_pos += m_vec;

	if (m_isExist)
	{
		m_vec.y = kGravity;
	}

	m_vec.y += kGravity;

	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}