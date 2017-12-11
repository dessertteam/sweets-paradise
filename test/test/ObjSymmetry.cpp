#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSymmetry.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSymmetry::Init()
{
	m_x = 360.0f; //位置
	m_y = 15.0f;
	m_speed = 3.3f; //速さ
	m_vx = 0.0f;
	m_vy = 0.0f;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_SYMMETRY, 1);
}

//アクション
void CObjSymmetry::Action()
{
	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);
	
	//領域外に出ない処理
	if (m_x + 64.0f > 800.0f)
	{
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 64.0f > 600.0f)
	{
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}

	//点対称(仮)------------------------------------------------------

	//主人公が右に行くと左に移動
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x -= m_speed;
	}

	//主人公が左に行くと右に移動
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x += m_speed;
	}

	//主人公が上に行くと下に移動
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y += m_speed;
	}

	//主人公が下へ行くと上に移動
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y -= m_speed;
	}

	//-----------------------------------------------------------------

	//点対称-----------------------------------------------------------

	//主人公の情報を取得
	//CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);



	//-----------------------------------------------------------------

	//ブロックタイプ検知用の変数がないためのためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//位置の更新
	m_x += m_vx;
	m_y += m_vy;
}

//ドロー
void CObjSymmetry::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 64.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 128.0f;
	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}