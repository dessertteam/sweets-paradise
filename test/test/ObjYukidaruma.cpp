//�g�p�w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjYukidaruma.h"
#include "UtilityModule.h"

#define FPS (60)

/*//�b���t���[��
#define SECOND_TO_FRAME(_sec)   ((_sec)*FPS)
//�t���[�����b
#define FRAME_TO_SECOND(_frame) ((_frame)/SECOND_TO_FRAME(1))

//�g�p����l�[���X�y�[�X
using namespace GameL;*/



//�C�j�V�����C�Y
void CObjYukidaruma::Init()
{
	m_x = 416.0f;
	m_y = 32.0f;

	w_ran = 0;

	m_vx = 0.0f;
	m_vy = 0.0f;

	//�Ǐ��L���p
	w_m_up = false;
	w_m_down = false;
	w_m_left = false;
	w_m_right = false;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vy, &m_vx);

	//�����蔻��pHitBox���쐬
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_YUKIDARUMA, 1);
}

//�A�N�V����
void CObjYukidaruma::Action()
{
	//�Ǐ����L�^
	//��
	if (m_hit_up = true) {
		w_m_up = true;
	}
	else if (m_hit_up = false) {
		w_m_up = false;
	}

	//��
	if (m_hit_down = true) {
		w_m_down = true;
	}
	else if (m_hit_down = false) {
		w_m_down = false;
	}

	//��
	if (m_hit_left = true) {
		w_m_left = true;
	}
	else if (m_hit_left = false) {
		w_m_left = false;
	}

	//�E
	if (m_hit_right = true) {
		w_m_right = true;
	}
	else if (m_hit_right = false) {
		w_m_right = false;
	}


	//�ǂƂ̏Փ˂Ń����_���ɕ����]������
	if (w_m_up == true && w_m_down == true && w_m_right == true && w_m_left == true) {
		m_y;
		m_x++;
	}

	////HitBox�̓��e���X�V
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//�Ⴞ��܂��̈�O�ɍs���Ȃ�����
	if (m_x + 32.0f > 800.0f) {
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f) {
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f) {
		m_y = 0.0f;
	}
	if (m_x < 0.0f) {
		m_x = 0.0f;
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

	//�ʒu�̍X�V
	m_x += m_vx;
	m_y += m_vy;
}

//�h���[
void CObjYukidaruma::Draw()
{
	//�`��J���[���@R=RED G=Green B=Blue A=Alpha(���ߏ��)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

			   //�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}