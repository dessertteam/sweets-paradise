//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjSweets.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�}�b�v�\��
CObjSweets::CObjSweets(int block[19][25])
{
	memcpy(m_block, block, sizeof(int)*(19 * 25));
}

//�C�j�V�����C�Y
void CObjSweets::Init()
{
	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_SWEETS, OBJ_SWEETS, 1);
}

//�A�N�V����
void CObjSweets::Action()
{

}

//�h���[
void CObjSweets::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_block[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f + 6;
				dst.m_left = j*32.0f + 4;
				dst.m_right = dst.m_left + 24.0f;
				dst.m_bottom = dst.m_top + 24.0f;

				if (m_block[i][j] == 2)
				{
					//��1:2+16�`22
					BlockDrawHouse(0.0f, 0.0f, &dst, c);
				}
				else if (m_block[i][j] == 3)
				{
					//��2:3+23�`29
					BlockDrawHouse(0.0f, 128.0f, &dst, c);
				}
				else if (m_block[i][j] == 4)
				{
					//��3:4+30�`36
					BlockDrawHouse(0.0f, 256.0f, &dst, c);
				}
				else if (m_block[i][j] == 5)
				{
					//��4:5+37�`43
					BlockDrawHouse(0.0f, 384.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawHouseMethod�֐�
//����1	float x		:���\�[�X�؂���ʒuX
//����2	float y		:���\�[�X�؂���ʒuY
//����3 RECT_F* dst :�`��ʒu
//����4 float c[]	:�J���[���
//�u���b�N��128*128����`��p�B���\�[�X�؂���ʒu�̂�x�Ey��
//�ݒ�ł���
void CObjSweets::BlockDrawHouse(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 128.0f;
	src.m_bottom = src.m_top + 128.0f;
	//�`��
	Draw::Draw(2, &src, dst, c, 0.0f);
}
