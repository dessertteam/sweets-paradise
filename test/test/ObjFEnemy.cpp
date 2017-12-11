//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjFEnemy.h"
#include"SceneMain.h"
#include"UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;
CObjFEnemy::CObjFEnemy(float x, float y)
{
	m_px = x;
	m_py = y;
}

//�C�j�V�����C�Y
void CObjFEnemy::Init()
{
	m_px = 416.0f;
	m_py = 32.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_FENEMY, 1);
}
float r = 0.0f;
//�A�N�V����
void CObjFEnemy::Action()
{
	//�A���ƓG�̊p�x�����
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_px;
		float y = obj->GetY() - m_py;
		float ar = GetAtan2Angle(x, -y);

		//�G�̌��݂̌����Ă���p�x�����
		float br = GetAtan2Angle(-m_vx, -m_vy);

		//�ړ��������A���̕����ɂ���
		m_vx = cos(3.14f / 180.0f * ar);
		m_vy = -sin(3.14f / 180.0f * ar);

		float r = 3.14f / 180.0f;
		/*if (ar < br)
		{
		//�ړ�������1��������
		m_vx = m_vx*cos(r) - m_vy*sin(r);
		m_vy = m_vy*cos(r) + m_vx*sin(r);
		}
		else
		{
		//�ړ�������-1��������
		m_vx = m_vx*cos(-r) - m_vy*sin(-r);
		m_vy = m_vy*cos(-r) + m_vx*sin(-r);
		}*/
		UnitVec(&m_vx, &m_vy);
	}
	m_px += m_vx*2.0f;
	m_py += m_vy*2.0f;

	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 32.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}

	//�G��HitBox�X�V�p�|�C���^�[�擾
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);            //HitBox�̈ʒu��G�̈ʒu�ɍX�V

										//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̂��߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_px, &m_py,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//�ʒu�̍X�V
	m_px += m_vx;
	m_py += m_vy;
}

//�h���[
void CObjFEnemy::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 64.0f;

	//�u���b�N���������Ă���
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f + m_px;
	dst.m_right = 0.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}