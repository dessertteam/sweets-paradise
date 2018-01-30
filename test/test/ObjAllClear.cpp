//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjAllClear::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

	//�Q�[�����s���Ĉ��̂�
	static bool init_point = false;
	if (init_point == false)
	{
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}

		//���[�h
		//Save::Open();//���t�H���_�uUserData�v����f�[�^�擾�B

		//�_����0�ɂ���
		init_point = true;
	}

	//���_���������L���O�ŉ���(�`�挗�O)�ɓo�^
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_cal;

	//���_���������ɕ��ёւ���
	RankingSort(((UserData*)Save::GetData())->m_ranking);

	//�Q�[�����s���Ĉ��݈̂ȊO�A�����L���O�������Z�[�u����
	if (init_point == true)
	{
		//Save::Seve();//UserData�̏��𓯃t�H���_�uUserData�v���쐬
	}

}

//�A�N�V����
void CObjAllClear::Action()
{
	//�}�E�X�̈ʒu���擾
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//�}�E�X�̃{�^���̏��
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//�����L���O���Z�b�g�̕����Ƃ̓����蔻��
	if (m_mou_x > CLICK_RESET_POS_X&&m_mou_x<CLICK_RESET_POS_X + 100 &&
		m_mou_y>CLICK_RESET_POS_Y&&m_mou_y < CLICK_RESET_POS_Y + 32)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			//�����L���O������
			for (int i = 0; i < 10; i++)
			{
				((UserData*)Save::GetData())->m_ranking[i] = 0;
			}
		}
		m_mou_r = false;
		m_mou_l = false;
	}

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

			   //�����L���O
	Font::StrDraw(L"�����L���O", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		swprintf_s(str, L"%2d��%12d�_", i + SCORE_INIT, ((UserData*)Save::GetData())->m_ranking[i]);
		Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
	}

	//�����L���O���Z�b�g�ꏊ
	Font::StrDraw(L"��ClickReset", CLICK_RESET_POS_X, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 113.0f;
	src.m_left = 5.0f;
	src.m_right = 508.0f;
	src.m_bottom = 146.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 140.0f;
	dst.m_left = 250.0f;
	dst.m_right = 850.0f;
	dst.m_bottom = 200.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);


}

//�����L���O�\�[�g���\�b�h
//����1 int[16] :�����L���O�p�z��
//�����Ńo�u���\�[�g���s��
void CObjAllClear::RankingSort(int rank[10])
{
	//�l�����p�ϐ�
	int w;

	//�o�u���\�[�g
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (rank[i] < rank[j])
			{
				//�l�̌���
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;

			}
		}
	}
}