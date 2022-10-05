#include "DxLib.h"
#include "SceneMain.h"

#include "ShotBound.h"
#include "ShotMeandeling.h"
#include "ShotNormal.h"
#include "ShotSlanting.h"

namespace
{
	//�V���b�g�̔��ˊԊu
	constexpr int kShotInterval = 16;
}

SceneMain::SceneMain()
{
	m_hPlayerGraphic = -1;
	m_hShotGraphic = -1;
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();
	m_player.setMain(this);	//���g�̃|�C���^���擾����ꍇ this ���g��

	for (auto& pShot : m_pShot)
	{
		pShot = nullptr;	//	���������Ă��Ȃ���Ԃŏ�����
	}
	
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& pShot : m_pShot)
	{
		if (!pShot)	continue;//nullptr�̎����ɂ͉����Ȃ�����delete���Ȃ�
		delete pShot;		//�m�ۂ���Ă�����delete
		pShot = nullptr;		//���g��nullptr��
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& pShot : m_pShot)
	{
		if (!pShot)	continue;//���g�����邩�ǂ����@nullptr�̎�continue
		pShot->update();
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& pShot : m_pShot)
	{
		if (!pShot)	continue;
		pShot->draw();
		if (!pShot->isExist())
		{
			delete pShot;
			pShot = nullptr;
		}
	}

	//���ݑ��݂��Ă���e�̐���\��
	int shotNum = 0;
	for (auto& pShot : m_pShot)
	{
		if (!pShot)	continue;
		if (pShot->isExist())	shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "�e�̐�:%d", shotNum);
}

//�e�̐���
bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& pShot : m_pShot)
	{
		if (pShot)	continue;	//���łɂ���ꍇ�͏������Ȃ�

		pShot = new ShotNormal;	//	����������������ƕύX�ł���
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& pShot : m_pShot)
	{
		if (pShot)	continue;

		pShot = new ShotBound;				//���������m��
		pShot->setHandle(m_hShotGraphic);	//�m�ۂ����������ɏZ�����w��
		pShot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotMeandeling(Vec2 pos)
{
	for (auto& pShot : m_pShot)
	{
		if (pShot)	continue;

		pShot = new ShotMeandeling;
		pShot->setHandle(m_hShotGraphic);
		pShot->start(pos);
		return true;
	}
	return false;
}