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

			   //壁情報記憶用
	bool w_m_up;
	bool w_m_down;
	bool w_m_left;
	bool w_m_right;
	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	int w_ran;   //ランダム初期化用
};