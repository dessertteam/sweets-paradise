#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g : �u���b�N&�w�i
class CObjSweets : public CObj
{
public:
	CObjSweets(int block[19][25]);
	~CObjSweets() {};
	void Init();	//�C�j�V�����C�Y
	void Action();	//�A�N�V����
	void Draw();	//�h���[

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }

	float GetX() { return m_x; }
	float GetY() { return m_y; }

	void SetMap(int x, int y, int e)
	{
		m_block[y][x] = e;
	}
	int GetMap(int x, int y)
	{
		return m_block[y][x];
	}

private:
	void BlockDrawHouse(float x, float y, RECT_F* dst, float c[]);

	int m_block[19][25];	//�}�b�v���
	int m_x;
	int m_y;
};