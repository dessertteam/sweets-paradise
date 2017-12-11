#pragma once
//使用ヘッダーファイル
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト:敵(ドーナツ)
class CObjSymmetry : public CObj
{
public:
	CObjSymmetry() {};
	~CObjSymmetry() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	float m_x; //位置
	float m_y;
	float m_vx;
	float m_vy;
	float m_speed; //速さ

				   //blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};