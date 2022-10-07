#include "DxLib.h"
#include "game.h"
#include "player.h"

#include "SceneMain.h"

namespace
{
	// X�����AY�����̍ő呬�x
	constexpr float kSpeedMax = 8.0f;
	constexpr float kAcc = 0.4f;

	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

Player::Player()
{
	m_handle = -1;
	m_pMain = nullptr;	//null�|�C���^�@�������Ȓl�����͂��ꂽ�珈�����I������
	m_shotInterval = 0;
	m_hShotSe = -1;
}

Player::~Player()
{
	
}

void Player::init()
{
	m_pos.x = 100.0f;
	m_pos.y = 100.0f;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
	m_shotInterval = 0;

	m_startPos.x = 160.0f;
	m_startPos.y = 132.0f;
}

void Player::update()
{
	// �p�b�h(�������̓L�[�{�[�h)����̓��͂��擾����
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	//�V���b�g��������
	m_shotInterval--;
	if (m_shotInterval < 0)	m_shotInterval = 0;

	if (m_shotInterval <= 0)
	{
		if (padState & PAD_INPUT_1)
		{
			if (m_pMain->createShotNormal(getStartPos()))
			{
				m_shotInterval = kShotInterval;
			}
			PlaySoundMem(m_hShotSe, DX_PLAYTYPE_BACK, true);
		}
		if (padState & PAD_INPUT_2)
		{
			if (m_pMain->createShotBound(getStartPos()))
			{
				m_shotInterval = kShotInterval;
			}
			PlaySoundMem(m_hShotSe, DX_PLAYTYPE_BACK, true);
		}
		if (padState & PAD_INPUT_3)
		{
			if (m_pMain->createShotSin(getStartPos()))
			{
				m_shotInterval = kShotInterval;
			}
			PlaySoundMem(m_hShotSe, DX_PLAYTYPE_BACK, true);
		}
	}

	if (padState & PAD_INPUT_UP)
	{
		//�����x��ω�
		m_vec.y -= kAcc;
		if (m_vec.y < -kSpeedMax)	m_vec.y = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_DOWN)
	{
		m_vec.y += kAcc;
		if (m_vec.y > kSpeedMax)	m_vec.y = kSpeedMax;
	}
	else
	{
		//�L�[�𗣂����炾�񂾂�x������
		m_vec.y *= 0.9f;
	}
	if (padState & PAD_INPUT_LEFT)
	{
		m_vec.x -= kAcc;
		if (m_vec.x < -kSpeedMax)	m_vec.x = -kSpeedMax;
	}
	else if (padState & PAD_INPUT_RIGHT)
	{
		m_vec.x += kAcc;
		if (m_vec.x > kSpeedMax)	m_vec.x = kSpeedMax;
	}
	else
	{
		m_vec.x *= 0.9f;
	}
	m_pos += m_vec;
	m_startPos += m_vec;
}

void Player::draw()
{
	DrawGraphF(m_pos.x, m_pos.y, m_handle, true);
}