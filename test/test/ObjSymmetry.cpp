#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSymmetry.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSymmetry::Init()
{
	m_x = 360.0f; //�ʒu
	m_y = 15.0f;
	m_speed = 3.3f; //����
	m_vx = 0.0f;
	m_vy = 0.0f;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SYMMETRY, 1);
}

//�A�N�V����
void CObjSymmetry::Action()
{
	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	
	//�̈�O�ɏo�Ȃ�����
	if (m_x + 64.0f > 800.0f)
	{
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 64.0f > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

	//�_�Ώ�(��)------------------------------------------------------

	//��l�����E�ɍs���ƍ��Ɉړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x -= m_speed;
	}

	//��l�������ɍs���ƉE�Ɉړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x += m_speed;
	}

	//��l������ɍs���Ɖ��Ɉړ�
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y += m_speed;
	}

	//��l�������֍s���Ə�Ɉړ�
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y -= m_speed;
	}

	//-----------------------------------------------------------------

	//�_�Ώ�-----------------------------------------------------------

	//��l���̏����擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);



	//-----------------------------------------------------------------

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̂��߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//�ʒu�̍X�V
	m_x += m_vx;
	m_y += m_vy;
}

//�h���[
void CObjSymmetry::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}