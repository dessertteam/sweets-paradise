#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : ブロック&背景
class CObjSweets : public CObj
{
public:
	CObjSweets(int block[19][25]);
	~CObjSweets() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

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

	int m_block[19][25];	//マップ情報
	int m_x;
	int m_y;
};