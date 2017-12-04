//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjFEnemy.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjFEnemy::Init()
{
	m_px = 0;
	m_py = 0;
}

//�A�N�V����
void CObjFEnemy::Action()
{
	//	�G���̈�O�ɍs���Ȃ�����
	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 64.0f;
	}
	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 64.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}
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
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_py;
	dst.m_left = 0.0f + m_px;
	dst.m_right = 64.0f + m_px;
	dst.m_bottom = 64.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}