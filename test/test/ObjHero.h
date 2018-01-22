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
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_x;		//�ʒu
	float m_y;
	float m_vx;		//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��

	bool m_f;//�Ȃ񂩂���݂���
	int z_cnt;//�y�L�[�̃J�E���g�p


	int m_time;         //��l���X�s�[�h�ϊ��p
	int m_ani_time;		//�A�j���[�V�����t���[������Ԋu
	int m_ani_frame;	//�`��t���[��

	float m_speed;	//��l��(�a)�̑���
	float m_ani_max_time;//�A�j���[�V�����t���[������Ԋu�ő�l

						 //�ǂƂ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//block�̎�ނ��m�F�p
	int m_block_type;
};