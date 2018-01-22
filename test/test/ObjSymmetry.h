
#pragma once
				   //�g�p�w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"
				   //�g�p����l�[���X�y�[�X
	using namespace GameL;

	//�I�u�W�F�N�g:�G(�h�[�i�c)
	class CObjSymmetry : public CObj
	{
	public:
		CObjSymmetry() {};
		~CObjSymmetry() {};
		void Init();   //�C�j�V�����C�Y
		void Action(); //�A�N�V����
		void Draw();   //�h���[
	private:
		float m_x; //�ʒu
		float m_y;
		float m_vx;
		float m_vy;
		float m_speed; //����

		float m_mx;//���X�ړ��ۑ��p
		float m_my;//���Y�ړ��ۑ��p
		int m_direc;//��̌����p 0:��,1:�E,2:��,3:��
		float memo;//�ړ��p�ϐ�
		int w_ranif; //�����_���C�t�p

		int m_ani_time;		//��̃A�j���[�V�����t���[������Ԋu
		int m_ani_frame;	//��̕`��t���[��
		float m_ani_max_time;//�I�̃A�j���[�V�����t���[������Ԋu�ő�l

							 //block�Ƃ̏Փˏ�Ԋm�F�p
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;
	};