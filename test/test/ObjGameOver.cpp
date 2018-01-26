#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[��Titlle�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}
}
//�h���[
void CObjGameOver::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src1;//�`�挳�؂���ʒu
	RECT_F dst1;//�`���\���ʒu

	RECT_F src2;//�`�挳�؂���ʒu
	RECT_F dst2;//�`���\���ʒu

				//�؂���ʒu�̐ݒ�
	src1.m_top = 155.0f;
	src1.m_left = 5.0f;
	src1.m_right = 508.0f;
	src1.m_bottom = 188.0f;

	//�؂���ʒu�̐ݒ�
	src2.m_top = 198.0f;
	src2.m_left = 5.0f;
	src2.m_right = 508.0f;
	src2.m_bottom = 230.0f;

	//�\���ʒu�̐ݒ�
	dst1.m_top = 240.0f;
	dst1.m_left = 250.0f;
	dst1.m_right = 850.0f;
	dst1.m_bottom = 300.0f;

	//�\���ʒu�̐ݒ�
	dst2.m_top = 420.0f;
	dst2.m_left = 230.0f;
	dst2.m_right = 830.0f;
	dst2.m_bottom = 470.0f;

	Draw::Draw(3, &src1, &dst1, c, 0.0f);
	Draw::Draw(3, &src2, &dst2, c, 0.0f);

	//Font::StrDraw(L"GameOver", 300, 250, 50, c);
	//Font::StrDraw(L"Push   EnterKey", 300, 400, 30, c);
}