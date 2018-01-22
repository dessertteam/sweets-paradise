#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Z�l(�S�I��)
class CObjOnikuri :public CObj
{
public:
	CObjOnikuri() {}
	~CObjOnikuri() {}

	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[


	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_x;//�I��X�����̈ʒu
	float m_y;//�I��Y�����̈ʒu
	float m_vx;//�I�̈ړ��x�N�g��X
	float m_vy;//�I�̈ړ��x�N�g��Y

	float m_mx;//�I��X�ړ��ۑ��p
	float m_my;//�I��Y�ړ��ۑ��p
	float memo;//�ړ��p�ϐ�
	int m_direc;//�I�̌����p 0:��,1:�E,2:��,3:��


	int m_ani_time;		//�I�̃A�j���[�V�����t���[������Ԋu
	int m_ani_frame;	//�I�̕`��t���[��

	float m_ani_max_time;//�I�̃A�j���[�V�����t���[������Ԋu�ő�l

						 //�Ǐ��L���p
	bool w_m_up;
	bool w_m_down;
	bool w_m_left;
	bool w_m_right;
	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int w_ranif; //�����_���C�t�p
};