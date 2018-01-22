
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

		float m_mx;//雪のX移動保存用
		float m_my;//雪のY移動保存用
		int m_direc;//雪の向き用 0:左,1:右,2:上,3:下
		float memo;//移動用変数
		int w_ranif; //ランダムイフ用

		int m_ani_time;		//雪のアニメーションフレーム動作間隔
		int m_ani_frame;	//雪の描画フレーム
		float m_ani_max_time;//栗のアニメーションフレーム動作間隔最大値

							 //blockとの衝突状態確認用
		bool m_hit_up;
		bool m_hit_down;
		bool m_hit_left;
		bool m_hit_right;
	};