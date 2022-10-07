#pragma once

#include "Vec2.h"

class SceneMain;	//���݂Ƀw�b�_�[�̃C���N���[�h���K�v�Ȏ��A��Ŏg���錾������

class Player
{
public:
	Player();
	virtual ~Player();

	// �O���t�B�b�N�f�[�^�ݒ�
	void setHandle(int handle) { m_handle = handle; }

	// �v���C���[�̏�����
	void init();
	//SceneMain�N���X�̃|�C���^
	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	// ����
	void update();
	// �`��
	void draw();

	// ���̎擾
	Vec2 getPos() const { return m_pos; }

	Vec2 getStartPos() const { return m_startPos; }

	void setShotSe(int shotSe){ m_hShotSe = shotSe; }
private:
	int m_handle;
	int m_hShotSe;
	//SceneMain�̃|�C���^
	SceneMain* m_pMain;

	// �\���ʒu
	Vec2 m_pos;
	// �ړ�
	Vec2 m_vec;
	//�V���b�g�̔��ˊԊu
	int m_shotInterval;

	//�V���b�g����̈ʒu���甭��
	Vec2 m_startPos;
};