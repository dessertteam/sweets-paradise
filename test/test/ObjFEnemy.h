#pragma once
//�g�p����w�b�_�[
#include"GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F����^�G
class CObjFEnemy : public CObj
{
public:
	CObjFEnemy(float x, float y);
	~CObjFEnemy() {};
	void Init(); //�C�j�V�����C�Y
	void Action();//�A�N�V����
	void Draw();  //�h���[

	void SetX(float x) { m_px = x; }
	void SetY(float y) { m_py = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	float GetX() { return m_px; }
	float GetY() { return m_py; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_px;//�ʒu
	float m_py;
	float m_vx;//�ړ��x�N�g��
	float m_vy;
	float m_posture;//�p��

	int m_ani_time;//�A�j���[�V����
	int m_ani_frame;//�`��t���[��

	float m_speed_power; //�X�s�[�h�p���[
	float m_ani_max_time;//�A�j���[�V����

						 //block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
	int m_time;
};