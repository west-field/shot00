#pragma once

#include "player.h"
#include "ShotBase.h"

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();

	//�e�̐���
	bool createShotNormal(Vec2 pos);
	bool createShotBound(Vec2 pos);
	bool createShotMeandeling(Vec2 pos);
	
private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 64;

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	//�V���b�g�̃O���t�B�b�N�n���h��
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �V���b�g

	ShotBase* m_pShot[kShotMax];//�x�[�X�N���X�̃|�C���^�Ɍp����̃N���X�����邱�Ƃ��ł���

//	ShotBound* m_pShotBound[kShotMax];//����
//	ShotMeandeling* m_pShotMeandeling[kShotMax];//�֍s
//	ShotNormal* m_pShotNormal[kShotMax];//�܂�����
// ShotSlanting* m_shot[kShotMax];//�΂�
//	ShotSin* m_shotSin[kShotMax];
};