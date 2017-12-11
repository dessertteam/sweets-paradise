//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjFEnemy.h"
#include"SceneMain.h"
#include"UtilityModule.h"

//使用するネームスペース
using namespace GameL;
CObjFEnemy::CObjFEnemy(float x, float y)
{
	m_px = x;
	m_py = y;
}

//イニシャライズ
void CObjFEnemy::Init()
{
	m_px = 416.0f;
	m_py = 32.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_px, m_py, 32, 32, ELEMENT_ENEMY, OBJ_FENEMY, 1);
}
float r = 0.0f;
//アクション
void CObjFEnemy::Action()
{
	//アリと敵の角度を取る
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float x = obj->GetX() - m_px;
		float y = obj->GetY() - m_py;
		float ar = GetAtan2Angle(x, -y);

		//敵の現在の向いている角度を取る
		float br = GetAtan2Angle(-m_vx, -m_vy);

		//移動方向をアリの方向にする
		m_vx = cos(3.14f / 180.0f * ar);
		m_vy = -sin(3.14f / 180.0f * ar);

		float r = 3.14f / 180.0f;
		/*if (ar < br)
		{
		//移動方向に1°加える
		m_vx = m_vx*cos(r) - m_vy*sin(r);
		m_vy = m_vy*cos(r) + m_vx*sin(r);
		}
		else
		{
		//移動方向に-1°加える
		m_vx = m_vx*cos(-r) - m_vy*sin(-r);
		m_vy = m_vy*cos(-r) + m_vx*sin(-r);
		}*/
		UnitVec(&m_vx, &m_vy);
	}
	m_px += m_vx*2.0f;
	m_py += m_vy*2.0f;

	if (m_px + 64.0f > 800.0f)
	{
		m_px = 800.0f - 32.0f;
	}
	if (m_py + 64.0f > 600.0f)
	{
		m_py = 600.0f - 32.0f;
	}
	if (m_py < 0.0f)
	{
		m_py = 0.0f;
	}
	if (m_px < 0.0f)
	{
		m_px = 0.0f;
	}

	//敵のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_px, m_py);            //HitBoxの位置を敵の位置に更新

										//ブロックタイプ検知用の変数がないためのためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_px, &m_py,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//位置の更新
	m_px += m_vx;
	m_py += m_vy;
}

//ドロー
void CObjFEnemy::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 64.0f;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = 0.0f + m_py;
	dst.m_left = 32.0f + m_px;
	dst.m_right = 0.0f + m_px;
	dst.m_bottom = 32.0f + m_py;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}