#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : ��
class CObjhole : public CObj
{
public:
	CObjhole() {}
	~CObjhole() {}

	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

private:
	float m_x;
	float m_y;
};