#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�Z�l(�Ⴞ���)
class CObjYukidaruma :public CObj
{
public:
	CObjYukidaruma() {}
	~CObjYukidaruma() {}

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
	float m_x;//���X�����̈ʒu
	float m_y;//���Y�����̈ʒu
	float m_vx;//��̈ړ��x�N�g��X
	float m_vy;//��̈ړ��x�N�g��Y

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

	int w_ran;   //�����_���������p
};