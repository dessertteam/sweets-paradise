#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��l��(�a)
class CObjHero : public CObj
{
public:
	CObjHero() {}
	~CObjHero() {}

	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_x;		//��l��(�a)��X�����ړ�
	float m_y;		//��l��(�a)��Y�����ړ�
	float m_speed;	//��l��(�a)�̑���
};