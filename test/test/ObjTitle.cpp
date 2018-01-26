#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjTitle.h"

//�g�p����˃l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{
	m_key_flag = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[�����C���Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}

	}
	else
	{
		m_key_flag = true;
	}
}
//�h���[
void CObjTitle::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src1;//�`�挳�؂���ʒu
	RECT_F dst1;//�`���\���ʒu

	RECT_F src2;//�`�挳�؂���ʒu
	RECT_F dst2;//�`���\���ʒu

	RECT_F src3;//�`�挳�؂���ʒu
	RECT_F dst3;//�`���\���ʒu

	RECT_F src4;//�`�挳�؂���ʒu
	RECT_F dst4;//�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src1.m_top = 30.0f;
	src1.m_left = 5.0f;
	src1.m_right = 336.0f;
	src1.m_bottom = 63.0f;

	//�؂���ʒu�̐ݒ�
	src2.m_top = 74.0f;
	src2.m_left = 5.0f;
	src2.m_right = 508.0f;
	src2.m_bottom = 105.0f;

	//�؂���ʒu�̐ݒ�
	src3.m_top = 238.0f;
	src3.m_left = 5.0f;
	src3.m_right = 508.0f;
	src3.m_bottom = 274.0f;

	//�؂���ʒu�̐ݒ�
	src4.m_top = 283.0f;
	src4.m_left = 5.0f;
	src4.m_right = 508.0f;
	src4.m_bottom = 315.0f;

	//�\���ʒu�̐ݒ�
	dst1.m_top = 100.0f;
	dst1.m_left = 100.0f;
	dst1.m_right = 700.0f;
	dst1.m_bottom = 200.0f;

	//�\���ʒu�̐ݒ�
	dst2.m_top = 370.0f;
	dst2.m_left = 170.0f;
	dst2.m_right = 620.0f;
	dst2.m_bottom = 440.0f;

	//�\���ʒu�̐ݒ�
	dst3.m_top = 500.0f;
	dst3.m_left = 25.0f;
	dst3.m_right = 410.0f;
	dst3.m_bottom = 530.0f;

	//�\���ʒu�̐ݒ�
	dst4.m_top = 500.0f;
	dst4.m_left = 415.0f;
	dst4.m_right = 790.0f;
	dst4.m_bottom = 530.0f;

	Draw::Draw(3, &src1, &dst1, c, 0.0f);
	Draw::Draw(3, &src2, &dst2, c, 0.0f);
	Draw::Draw(3, &src3, &dst3, c, 0.0f);
	Draw::Draw(3, &src4, &dst4, c, 0.0f);

	//Font::StrDraw(L"SweetParadise", 150, 100, 70, c);
	//Font::StrDraw(L"GameStart:Push EnterKey", 210, 400, 30, c);
	//Font::StrDraw(L"������@�@�\���L�[�F�ړ��@Z�L�[�F�X�^�[�g�ʒu�ɖ߂�", 25, 500, 30, c);
}