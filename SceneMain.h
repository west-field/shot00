#pragma once

#include "player.h"
#include "ShotParabola.h"

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
	bool createShot(Vec2 pos);
	
private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 64;

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �V���b�g
//	ShotNormal m_shot[kShotMax];//�܂�����
// ShotSlanting m_shot[kShotMax];//�΂�
	ShotParabola m_shot[kShotMax];//������

};