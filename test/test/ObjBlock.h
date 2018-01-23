#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �u���b�N&�w�i
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[19][25]);
	~CObjBlock() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

					//�u���b�N�Ƃ̓����蔻��
	void BlockHit(
		float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	//void BlockDrawHouse(float x, float y, RECT_F* dst, float c[]);

	int m_map[19][25];	//�}�b�v���
	int m_block[19][25]; //�f�[�^���
	int m_x;
	int m_y;
};