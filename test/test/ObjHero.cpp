//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjHero.h"
#include "UtilityModule.h"

#include <time.h>

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_x = 416.0f;
	//m_y = 0.0f;
	m_y = 544.0f;		//�ʒu
	m_vx = 0.0f;
	m_vy = 0.0f;		//�ړ��x�N�g��
	m_posture = 0.0f;	//�E����0.0f ������1.0f

	m_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1;	//�Î~�t���[���������ɂ���

	z_cnt = 3;//�y�L�[�̎g�p��

	m_speed = 2.0f;	//��l���̑���
	m_ani_max_time = 4;//�A�j���[�V�����Ԋu��

					   //�ǂƂ̏Փˏ�Ԋm�F�p
	bool m_hit_up = false;
	bool m_hit_down = false;
	bool m_hit_left = false;
	bool m_hit_right = false;

	m_block_type = 0; //block�̎�ނ��m�F�p

					  //�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//�A�N�V����
void CObjHero::Action()
{
	//�ړ��x�N�g���̔j��
	m_vx = 0.0f;
	m_vy = 0.0f;

	//��l��(�a)�̈ړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += m_speed;
		m_posture = 1.0f;
		m_ani_time += 1;

	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= m_speed;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= m_speed;
		m_ani_time += 1;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += m_speed;
		m_ani_time += 1;
	}

	//�����ʒu(�\��)�ɖ߂�
	if (z_cnt > 0)
	{
		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
				m_x = 416.0f;
				m_y = 544.0f;
				m_vx = 0.0f;
				m_vy = 0.0f;
				z_cnt--;
				m_f = false;
			}
		}
		else
		{
			m_f = true;
		}
	}

	//��l��(�a)���̈�O����t���Ƀ��[�v���鏈��
	if (m_x >= 795.0f)
	{
		m_y = 288.0f;
		m_x = -31.0f;
	}
	else if (m_x <= -32.0f)
	{
		m_y = 288.0f;
		m_x = 794.0f;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	m_time += 1;

	if (m_time > 1800)
		m_speed = 4.0f;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &m_block_type
	);

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);    //�쐬����HitBox�X�V�p�̓���������o��
	hit->SetPos(m_x, m_y);

	//ELEMENT_ENEMY�����I�u�W�F�N�g�ƐڐG�������l���@�폜
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);//���g�ɍ폜���߂��o���B
		Hits::DeleteHitBox(this);//��l���@�����L����HitBox�ɍ폜����B

								 //��l���@���łŃV�[�����Q�[���I�[�o�[�Ɉڍs����
		Scene::SetScene(new CSceneGameOver());
	}

	//�ʒu�̍X�V
	m_x += m_vx;
	m_y += m_vy;
}

//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		0,1,0,1,
	};

	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 128.0f + AniData[m_ani_frame] * 64;
	src.m_right = 192.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = (32.0f - 32.0f * m_posture) + m_x;
	dst.m_right = 32.0f*m_posture + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}