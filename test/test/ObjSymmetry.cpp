//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSymmetry.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

//�����_���p�w�b�_�[
#include <stdlib.h>
#include <time.h>

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSymmetry::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_x = 96.0f;
	m_y = 96.0f;

	m_mx = 2;
	m_my = 0;

	m_direc = 1;

	memo = 2;

	m_ani_time = 0;
	m_ani_frame = 0;	//�Î~�t���[���������ɂ���

	m_ani_max_time = 1800;//�A�j���[�V�����Ԋu��

	w_ranif = 0;

	srand(unsigned(time(NULL)));//�����_������������
	w_ranif = rand() % 3 + 1;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SYMMETRY, 1);
}

//�A�N�V����
void CObjSymmetry::Action()
{
	/*
	//�̈�O�ɏo�Ȃ�����
	if (m_x + 32.0f > 800.0f)
	{
	m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f)
	{
	m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
	m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
	m_x = 0.0f;
	}
	*/

	//�����ʒu����̈ړ�
	//�����画�f���Ă���
	//[2][2]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 32 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 32 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][6]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][10]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][14]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 3 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 3 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}


	//[2][20]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][24]
	//����
	if (m_direc == 1 && m_x == 736 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 2 && m_x == 736 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[4][4]
	//�p�^�[��1
	//�E��
	if (m_direc == 2 && m_x == 96 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 0 && m_x == 96 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][6]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][7]
	//�p�^�[��1
	//����
	if (m_direc == 2 && m_x == 192 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 1 && m_x == 192 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][9]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 256 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 256 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][10]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][12]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 3 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 3 + 1;
	}

	//��[4][14]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//���
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��4
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][17]
	//�p�^�[��1
	//����
	if (m_direc == 2 && m_x == 512 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 3 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 1 && m_x == 512 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
	}

	//[4][19]
	//�p�^�[��1
	//�E��
	if (m_direc == 2 && m_x == 576 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 0 && m_x == 576 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][20]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][22]
	//�p�^�[��1
	//����
	if (m_direc == 2 && m_x == 672 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 1 && m_x == 672 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][2]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//���
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//��[6][4]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//���
	else if (m_direc == 2 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 2 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][22]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][24]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}

	//[7][4]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 96 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 96 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][6]
	//�p�^�[��1
	//����
	else if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][7]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 192 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 192 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[7][9]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 256 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 256 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][12]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 352 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 352 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[7][14]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 416 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 416 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][17]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[7][19]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 576 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 576 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][20]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][22]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 672 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 672 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][2]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[9][4]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 96 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 96 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][6]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[9][8]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][17]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][18]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 544 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 544 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][22]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 672 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 672 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][24]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][0]
	if (m_x == -32 && m_y == 288 && m_direc == 0)
	{
		m_x = 800; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[10][2]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][18]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][20]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][24]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][25]
	if (m_x == 832 && m_y == 288 && m_direc == 1)
	{
		m_x = -32; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][4]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 96 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 96 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][6]
	//�p�^�[��1
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[11][8]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 224 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 224 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][10]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][16]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][18]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 544 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 544 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[11][20]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[11][22]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 672 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 672 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][4]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 96 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 96 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][6]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][7]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 192 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 192 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][9]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 256 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 256 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][10]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][12]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 352 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 352 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][14]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 416 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 416 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][16]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][17]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 512 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 512 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][19]
	//�p�^�[��1
	//����
	if (m_direc == 0 && m_x == 576 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && m_x == 576 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][20]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][22]
	//�p�^�[��1
	//����
	if (m_direc == 1 && m_x == 672 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && m_x == 672 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[14][2]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][4]
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][7]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][9]
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][22]
	//�p�^�[��1
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][24]
	//���
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[16][4]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 96 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 96 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][6]
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][7]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 192 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 192 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[16][9]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 256 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 256 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][12]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 352 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 352 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[16][14]
	//���
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//�E��
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[16][17]
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][19]
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][20]
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//����
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][22]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 672 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 672 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[18][2]
	//�p�^�[��1
	//���
	if (m_direc == 0 && m_x == 32 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 3 && m_x == 32 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][6]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][14]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][20]
	//�p�^�[��1
	//����
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//�E��
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//���
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��3
	//����
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//�E��
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][24]
	//�p�^�[��1
	//���
	if (m_direc == 1 && m_x == 736 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//�p�^�[��2
	//����
	else if (m_direc == 3 && m_x == 736 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	m_x += m_mx;
	m_y += m_my;
	m_ani_time += 1;


	/*
	//�_�Ώ�(��)------------------------------------------------------

	//��l�����E�ɍs���ƍ��Ɉړ�
	if (Input::GetVKey(VK_RIGHT) == true)
	{
	m_x -= m_speed;
	}

	//��l�������ɍs���ƉE�Ɉړ�
	if (Input::GetVKey(VK_LEFT) == true)
	{
	m_x += m_speed;
	}

	//��l������ɍs���Ɖ��Ɉړ�
	if (Input::GetVKey(VK_UP) == true)
	{
	m_y += m_speed;
	}

	//��l�������֍s���Ə�Ɉړ�
	if (Input::GetVKey(VK_DOWN) == true)
	{
	m_y -= m_speed;
	}

	//-----------------------------------------------------------------

	//�_�Ώ�-----------------------------------------------------------

	//��l���̏����擾
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);



	//-----------------------------------------------------------------

	*/

	if (m_ani_time > 1800)
		memo = 4.0f;

	//�I�̃A�j���[�V�����H
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	//�u���b�N�^�C�v���m�p�̕ϐ����Ȃ����߂̂��߂̃_�~�[
	int d;

	//�u���b�N�Ƃ̓����蔻����s
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�ʒu�̍X�V
	m_x += m_vx;
	m_y += m_vy;
}

//�h���[
void CObjSymmetry::Draw()
{
	int AniData[10] =
	{
		0,1,0,1,
	};

	//�`��J���[���
	float c[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//�؂���ʒu�̐ݒ�
	src.m_top = 64.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 128.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}