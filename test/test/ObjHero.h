#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 主人公(蟻)
class CObjHero : public CObj
{
public:
	CObjHero() {}
	~CObjHero() {}

	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_x;		//位置
	float m_y;
	float m_vx;		//移動ベクトル
	float m_vy;
	float m_posture;//姿勢

	bool m_f;//なんかいるみたい
	int z_cnt;//Ｚキーのカウント用


	int m_time;         //主人公スピード変換用
	int m_ani_time;		//アニメーションフレーム動作間隔
	int m_ani_frame;	//描画フレーム

	float m_speed;	//主人公(蟻)の速さ
	float m_ani_max_time;//アニメーションフレーム動作間隔最大値

						 //壁との衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	//blockの種類を確認用
	int m_block_type;
};