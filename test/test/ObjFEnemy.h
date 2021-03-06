#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：先回り型敵
class CObjFEnemy : public CObj
{
public:
	CObjFEnemy(float x, float y);
	~CObjFEnemy() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー

	void SetX(float x) { m_x = x; }
	void SetY(float y) { m_y = y; }
	void SetVY(float vy) { m_vy = vy; }
	void SetVX(float vx) { m_vx = vx; }

	float GetX() { return m_x; }
	float GetY() { return m_y; }
	float GetVY() { return m_vy; }
	float GetVX() { return m_vx; }

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_x;//位置
	float m_y;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢

	float m_mx;//おばけのX移動保存用
	float m_my;//おばけのY移動保存用
	float memo;//移動用変数
	int m_direc;//おばけの向き用 0:左,1:右,2:上,3:下

	int w_ranif; //ランダムイフ用

	int m_ani_time;//アニメーション
	int m_ani_frame;//描画フレーム

	float m_speed_power; //スピードパワー
	float m_ani_max_time;//アニメーション

						 //blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int m_time;
};