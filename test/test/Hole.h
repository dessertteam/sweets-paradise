#pragma once
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��
class Hole
{
public:
	Hole();
	~Hole();

	void Init();
	void Action();
	void Draw();

	float m_ani_max_time;//�A�j���[�V�����t���[������Ԋu�ő�l
	int m_ani_time;		//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;	//�`��t���[��

	float m_x;//�ʒux
	float m_y;//�ʒuy

};

