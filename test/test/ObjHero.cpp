//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjHero.h"
#include "UtilityModule.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

#include <time.h>

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_x = 416.0f;
	m_y = 544.0f;		//位置
	m_vx = 0.0f;
	m_vy = 0.0f;		//移動ベクトル
	m_posture = 0.0f;	//右向き0.0f 左向き1.0f
	GetSweets = 0;//取った数
	Point = 0;//ポイント

	s_cnt = 0;
	m_time = 0;
	m_ani_time = 0;
	m_ani_frame = 1;	//静止フレームを初期にする

	z_cnt = 3;//Ｚキーの使用回数

	m_speed = 2.0f;	//主人公の速さ
	m_ani_max_time = 4;//アニメーション間隔幅

					   //壁との衝突状態確認用
	bool m_hit_up = false;
	bool m_hit_down = false;
	bool m_hit_left = false;
	bool m_hit_right = false;

	m_block_type = 0; //blockの種類を確認用

					  //得点の初期化
	((UserData*)Save::GetData())->m_cal = 0;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_PLAYER, OBJ_HERO, 1);
}

//アクション
void CObjHero::Action()
{
	//移動ベクトルの破棄
	m_vx = 0.0f;
	m_vy = 0.0f;

	//主人公(蟻)の移動
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += m_speed;
		m_posture = 1.0f;
		m_ani_time += 1;

	}
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= m_speed;
		m_posture = 0.0f;
		m_ani_time += 1;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= m_speed;
		m_ani_time += 1;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += m_speed;
		m_ani_time += 1;
	}

	CObjSweets* SweetsBlock = (CObjSweets*)Objs::GetObj(OBJ_SWEETS);

	if (m_time > 1800 && s_cnt == 0)
	{
		if (SweetsBlock->GetMap(13, 9 == 0))
		{
			SweetsBlock->SetMap(12, 8, 5);
		}
		s_cnt++;
	}

	if (SweetsBlock->GetMap((m_x + 16) / 32, (m_y + 16) / 32) == 2)
	{
		SweetsBlock->SetMap((m_x + 16) / 32, (m_y + 16) / 32, 0);
		GetSweets += 1;
		Point += 100;
		//得点の追加
		((UserData*)Save::GetData())->m_cal += 100;

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));
		Audio::Start(2);
	}
	if (SweetsBlock->GetMap((m_x + 16) / 32, (m_y + 16) / 32) == 3)
	{
		SweetsBlock->SetMap((m_x + 16) / 32, (m_y + 16) / 32, 0);
		GetSweets += 1;
		Point += 200;
		//得点の追加
		((UserData*)Save::GetData())->m_cal += 200;

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));
		Audio::Start(2);
	}
	if (SweetsBlock->GetMap((m_x + 16) / 32, (m_y + 16) / 32) == 4)
	{
		SweetsBlock->SetMap((m_x + 16) / 32, (m_y + 16) / 32, 0);
		GetSweets += 1;
		Point += 500;
		//得点の追加
		((UserData*)Save::GetData())->m_cal += 500;

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));
		Audio::Start(2);
	}
	if (SweetsBlock->GetMap((m_x + 16) / 32, (m_y + 16) / 32) == 5)
	{
		SweetsBlock->SetMap((m_x + 16) / 32, (m_y + 16) / 32, 0);
		GetSweets += 1;
		Point += 5000;
		//得点の追加
		((UserData*)Save::GetData())->m_cal += 5000;

		//ボリュームを1.0に戻す
		float v = Audio::VolumeMaster(0);
		v = Audio::VolumeMaster((1.0 - v));
		Audio::Start(2);
	}

	if (GetSweets > 19 && m_x == 416 && m_y == 544)
	{
		Scene::SetScene(new CSceneAllClear());
	}

	//初期位置(予定)に戻る
	if (z_cnt > 0)
	{
		if (Input::GetVKey('Z') == true)
		{
			if (m_f == true)
			{
				m_x = 416.0f;
				m_y = 544.0f;
				m_vx = 0.0f;
				m_vy = 0.0f;
				z_cnt--;
				m_f = false;
			}
		}
		else
		{
			m_f = true;
		}
	}

	//主人公(蟻)が領域外から逆側にワープする処理
	if (m_x >= 795.0f)
	{
		m_y = 288.0f;
		m_x = -31.0f;
	}
	else if (m_x <= -32.0f)
	{
		m_y = 288.0f;
		m_x = 794.0f;
	}

	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
	}

	m_time += 1;

	if (m_time > 1800)
		m_speed = 4.0f;

	//ブロックとの当たり判定実行
	CObjBlock* pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &m_block_type
	);

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);    //作成したHitBox更新用の入り口を取り出す
	hit->SetPos(m_x, m_y);

	//ELEMENT_ENEMYを持つオブジェクトと接触したら主人公機削除
	if (hit->CheckElementHit(ELEMENT_ENEMY) == true)
	{
		this->SetStatus(false);//自身に削除命令を出す。
		Hits::DeleteHitBox(this);//主人公機が所有するHitBoxに削除する。

								 //主人公機消滅でシーンをゲームオーバーに移行する
		Scene::SetScene(new CSceneGameOver());
	}

	//位置の更新
	m_x += m_vx;
	m_y += m_vy;
}

//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		0,1,0,1,
	};

	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	wchar_t str[128];
	swprintf_s(str, L"%d Cal", Point);//秒の値を文字列化
	Font::StrDraw(str, 700, 10, 20, c);

	wchar_t ttr[128];
	swprintf_s(ttr, L"%d 個", GetSweets);//秒の値を文字列化
	Font::StrDraw(ttr, 600, 10, 20, c);

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 128.0f + AniData[m_ani_frame] * 64;
	src.m_right = 192.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 64.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = (32.0f - 32.0f * m_posture) + m_x;
	dst.m_right = 32.0f*m_posture + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}