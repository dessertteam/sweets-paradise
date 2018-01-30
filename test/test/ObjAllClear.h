#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�萔
//�}�E�X�N���b�N�̃��C���J��
#define MOU_MAIN_HIT_X (230)
#define MOU_MAIN_HIT_W (450)
#define MOU_MAIN_HIT_Y (400)
#define MOU_MAIN_HIT_H (430)

//�`��֌W�̒萔
#define TITLE_POS_X		(200)
#define TITLE_POS_Y		(250)
#define TITLE_FONT_SIZE (40)

#define RANKING_POS_X	  (310)
#define RANKING_POS_Y	  (250)
#define RANKING_FONT_SIZE (32)
#define RANKING_SCORE_MAX (9)
#define STR_MAX			  (256)
#define SCORE_INIT		  (1)
#define SCORE_POS_X		  (260)
#define SCORE_POS_Y		  (304)
#define SCORE_POINT_MAX	  (100)
#define SCORE_INTERVAL	  (24)
#define SCORE_FONT_SIZE	  (24)

#define CLICK_START_POS_X	  (230)
#define CLICK_START_POS_Y	  (400)
#define CLICK_START_FONT_SIZE (30)

#define CLICK_RESET_POS_X	  (260)
#define CLICK_RESET_POS_Y	  (530)
#define CLICK_RESET_FONT_SIZE (32)

//�I�u�W�F�N�g : �I�[���N���A
class CObjAllClear :public CObj
{
public:
	CObjAllClear() {};
	~CObjAllClear() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[
private:
	float m_mou_x;  //�}�E�X�̈ʒuX
	float m_mou_y;  //�}�E�X�̈ʒuY
	bool  m_mou_r;  //�}�E�X�̉E�{�^��
	bool  m_mou_l;  //�}�E�X�̍��{�^��

	bool m_key_flag;//�L�[�t���O

					//�����L���O�\�[�g���\�b�h
	void RankingSort(int rank[10]);
};