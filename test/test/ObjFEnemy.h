#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：先回り型敵
class CObjFEnemy : public CObj
{
public:
	CObjFEnemy() {};
	~CObjFEnemy() {};
	void Init(); //イニシャライズ
	void Action();//アクション
	void Draw();  //ドロー

private:
	float m_px;//位置
	float m_py;
	float m_vx;//移動ベクトル
	float m_vy;
	float m_posture;//姿勢

	int m_ani_time;//アニメーション
	int m_ani_frame;//描画フレーム

	float m_speed_power; //スピードパワー
	float m_ani_max_time;//アニメーション

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;
};