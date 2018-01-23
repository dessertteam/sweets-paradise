#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : ブロック&背景
class CObjBlock : public CObj
{
public:
	CObjBlock(int map[19][25]);
	~CObjBlock() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

					//ブロックとの当たり判定
	void BlockHit(
		float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy, int* bt
	);
private:
	void BlockDraw(float x, float y, RECT_F* dst, float c[]);
	//void BlockDrawHouse(float x, float y, RECT_F* dst, float c[]);

	int m_map[19][25];	//マップ情報
	int m_block[19][25]; //データ情報
	int m_x;
	int m_y;
};