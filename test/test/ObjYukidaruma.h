#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//住人(雪だるま)
class CObjYukidaruma :public CObj
{
public:
	CObjYukidaruma() {}
	~CObjYukidaruma() {}

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
	void SetLeft(bool b) { m_hit_left = b = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_x;//雪のX方向の位置
	float m_y;//雪のY方向の位置
	float m_vx;//雪の移動ベクトルX
	float m_vy;//雪の移動ベクトルY
	float m_mx;//雪のX移動保存用
	float m_my;//雪のY移動保存用
	float memo;//移動用変数
	int m_direc;//雪の向き用 0:左,1:右,2:上,3:下

	int m_ani_time;		//雪のアニメーションフレーム動作間隔
	int m_ani_frame;	//雪の描画フレーム
	float m_ani_max_time;//栗のアニメーションフレーム動作間隔最大値

						 //blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int w_ranif; //ランダムイフ用
};