//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjAllClear::Init()
{

}

//�A�N�V����
void CObjAllClear::Action()
{

	//�G���^�[�L�[�������ăV�[��:�^�C�g���Ɉڍs����
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
void CObjAllClear::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 113.0f;
	src.m_left = 5.0f;
	src.m_right = 508.0f;
	src.m_bottom = 146.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 240.0f;
	dst.m_left = 250.0f;
	dst.m_right = 850.0f;
	dst.m_bottom = 300.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	//Font::StrDraw(L"GameClear", 300, 250, 50, c);
}