#include "game.h"
#include "ShotParabola.h"

namespace
{
	constexpr float kShotSpeed = 8.0f;
	constexpr float ksinRate = -1.0f;
}

//�V���b�g�J�n
void ShotParabola::start(Vec2 pos)
{
	ShotBase::start(pos);

	m_vec.x = kShotSpeed;
	m_vec.y = 0.0f;
}
// �X�V
void ShotParabola::update()
{
	if (!m_isExist)	return;
	m_pos += m_vec;



	if (m_pos.x > Game::kScreenWidth)
	{
		m_isExist = false;
	}
}