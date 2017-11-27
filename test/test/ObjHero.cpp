//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHero.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_x = 0;
	m_y = 0;
	m_speed = 3.0f;
}

//�A�N�V����
void CObjHero::Action()
{
	//��l��(�a)�̈ړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += m_speed;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= m_speed;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= m_speed;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += m_speed;
	}

	//�����ʒu(�\��)�ɖ߂�
	if (Input::GetVKey('Z') == true)
	{
		m_x = 360.0f;
		m_y = 520.0f;
	}

	//��l��(�a)���̈�O�ɍs���Ȃ�����
	if (m_x + 64.0f > 800.0f)
	{
		m_x = 800.0f - 64.0f;
	}
	if (m_y + 64.0f > 600.0f)
	{
		m_y = 600.0f - 64.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}
}

//�h���[
void CObjHero::Draw()
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
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}