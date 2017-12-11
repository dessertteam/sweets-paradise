#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : ブロック&背景
class CObjBlock : public CObj
{
public:
	CObjBlock() {};
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
	int m_map[19][25];	//マップ情報(仮)
};