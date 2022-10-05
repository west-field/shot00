#include "DxLib.h"
#include "SceneMain.h"

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

	for (auto& shot : m_pShotNormal)
	{
		shot = nullptr;	//	���������Ă��Ȃ���Ԃŏ�����
	}
	for (auto& shot : m_pShotBound)
	{
		shot = nullptr;
	}
	for (auto& shot : m_pShotMeandeling)
	{
		shot = nullptr;
	}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);

	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;//nullptr�̎����ɂ͉����Ȃ�����delete���Ȃ�
		delete shot;		//�m�ۂ���Ă�����delete
		shot = nullptr;		//���g��nullptr��
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		delete shot;
		shot = nullptr;
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		delete shot;
		shot = nullptr;
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;//���g�����邩�ǂ����@nullptr�̎�continue
		shot->update();
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		shot->update();
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		shot->update();
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();

	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		shot->draw();
		if (!shot->isExist())
		{
			delete shot;
			shot = nullptr;
		}
	}

	//���ݑ��݂��Ă���e�̐���\��
	int shotNum = 0;
	for (auto& shot : m_pShotNormal)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Normal:%d", shotNum);
	
	shotNum = 0;
	for (auto& shot : m_pShotBound)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 20, GetColor(255, 255, 255), "Bound:%d", shotNum);

	shotNum = 0;
	for (auto& shot : m_pShotMeandeling)
	{
		if (!shot)	continue;
		if (shot->isExist())	shotNum++;
	}
	DrawFormatString(0, 40, GetColor(255, 255, 255), "Meandeling:%d", shotNum);

}

//�e�̐���
bool SceneMain::createShotNormal(Vec2 pos)
{
	for (auto& shot : m_pShotNormal)
	{
		if (shot)	continue;	//���łɂ���ꍇ�͏������Ȃ�

		shot = new ShotNormal;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotBound(Vec2 pos)
{
	for (auto& shot : m_pShotBound)
	{
		if (shot)	continue;

		shot = new ShotBound;				//���������m��
		shot->setHandle(m_hShotGraphic);	//�m�ۂ����������ɏZ�����w��
		shot->start(pos);
		return true;
	}
	return false;
}
bool SceneMain::createShotMeandeling(Vec2 pos)
{
	for (auto& shot : m_pShotMeandeling)
	{
		if (shot)	continue;

		shot = new ShotMeandeling;
		shot->setHandle(m_hShotGraphic);
		shot->start(pos);
		return true;
	}
	return false;
}