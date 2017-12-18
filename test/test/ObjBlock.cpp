//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBlock::Init()
{
	//�}�b�v���
	int map[19][25] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1 },
		{ 1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1 },
		{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1 },
		{ 0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0 },
		{ 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1 },
		{ 1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};

	memcpy(m_map, map, sizeof(int)*(19 * 25));
}

//�A�N�V����
void CObjBlock::Action()
{
	//��l��(�a)�̈ʒu���擾

	//��l���Ɗp�x�����
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//�G(�Ⴞ��܁j�Ɗp�x�����
	CObjYukidaruma*obj_yukidaruma = (CObjYukidaruma*)Objs::GetObj(OBJ_YUKIDARUMA);

	//�G�i����j�Ɗp�x�����
	CObjFEnemy*obj_fenemy = (CObjFEnemy*)Objs::GetObj(OBJ_FENEMY);

	CObjHero hero;

	
}

//�h���[
void CObjBlock::Draw()
{
	
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   /*//�w�i�\��
			   src.m_top = 0.0f;
			   src.m_left = 512.0f;
			   src.m_right = 0.0f;
			   src.m_bottom = 512.0f;
			   dst.m_top = 0.0f;
			   dst.m_left = 0.0f;
			   dst.m_right = 800.0f;
			   dst.m_bottom = 600.0f;
			   Draw::Draw(0, &src, &dst, c, 0.0f);*/

	//�؂���ʒu�̐ݒ�
	src.m_top = 256.0f;
	src.m_left = 512.0f;
	src.m_right = 0.0f;
	src.m_bottom = 512.0f;

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] ==1)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				Draw::Draw(0, &src, &dst, c, 0.0f);
			}
			else if (m_map[i][j] >= 10)
			{
				

				//�\���ʒu�̐ݒ�
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				//�`��
				printf("%d", m_map[i][j]);
			}
		}
	}
}

//BlockHit�֐�
//����1		float*	x		:������s��object��X�ʒu
//����2		float*	y		:������s��object��Y�ʒu
//����4		bool*	up		:�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����5		bool*	down	:�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����6		bool*	left	:�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����7		bool*	right	:�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����8		float*	vx		:���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����9		float*	vy		:�㉺���莞�ɂ�鎩�R�����^���̈ړ������E�͂̒l��ς��ĕԂ�
//����10	int*	bt		:���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N32*32����ŁA�����蔻��Ə㉺���E���s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(
	float* x, float* y,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy, int* bt
)
{
	//��l���̏Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//����ł���block�̎�ނ̏�����
	*bt = 0;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j*32.0f;
				float by = i*32.0f;

				//��l��(�a)�ƃu���b�N�̓����蔻��
				if ((*x + 32.0f > bx) && (*x < bx + 32.0f) && (*y + 32.0f > by) && (*y < by + 32.0f))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = *x - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt(rvx*rvx + rvy*rvy);

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//len��������̒������Z���ꍇ����ɓ���
					if (len < 43.0f)
					{
						//�p�x�ŏ㉺���E�𔻒�
						if ((r < 45 && r >= 0) || r > 315)
						{
							//�E
							*right = true;//��l���̍��̕������Փ˂��Ă���
							*x = bx + 32.0f;//�u���b�N�̈ʒu+��l���̕�
							*vx = 0.0f;//-VX*�����W��

						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//��l���̉��̕������Փ˂��Ă���
							*y = by - 32.0f;//�u���b�N�̈ʒu-��l���̕�
							*vy = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//��l���̉E�̕������Փ˂��Ă���
							*x = bx - 32.0f;//�u���b�N�̈ʒu-��l���̕�
							*vx = 0.0f;//-VX*�����W�� -(*vx)*0.1f;
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//��l���̏�̕������Փ˂��Ă���
							*y = by + 32.0f;//�u���b�N�̈ʒu+��l���̕�
							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}