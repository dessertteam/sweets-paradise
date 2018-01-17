#include "Hole.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjHero.h"

bool flag;

//�R���X�g���N�^
Hole::Hole()
{
}

//�f�X�g���N�^
Hole::~Hole()
{
}
//�C�j�V�����C�Y
 void Hole::Init()
{

}
 //�A�N�V����
 void Hole::Action()
 {
	 if (Input::GetVKey('Z') == true)
	 {
		 flag = true;

		 float GetX();
		 float GetY();

		 
	 }
	 else
	 {
		 flag = false;
	 }
 }

 //�h���[
 void Hole::Draw()
 {
	
	 //�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	 float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	 RECT_F src;//�`�挳�؂���ʒu
	 RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	 src.m_top = 128.0f;
	 src.m_left = 128.0f;
	 src.m_right = 192.0f;
	 src.m_bottom = 192.0f;

	 //�\���ʒu�̐ݒ�
	 dst.m_top = 0.0f + m_y;
	 dst.m_left = 0.0f + m_x;
	 dst.m_right = 32.0f + m_x;
	 dst.m_bottom = 32.0f + m_y;

	 if (flag == true)
	 {
		 Draw::Draw(0, &src, &dst, c, 0.0f);
	 }
 }
