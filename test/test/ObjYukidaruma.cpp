//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "ObjYukidaruma.h"
#include "UtilityModule.h"

#define FPS (60)

/*//秒→フレーム
#define SECOND_TO_FRAME(_sec)   ((_sec)*FPS)
//フレーム→秒
#define FRAME_TO_SECOND(_frame) ((_frame)/SECOND_TO_FRAME(1))

//使用するネームスペース
using namespace GameL;*/



//イニシャライズ
void CObjYukidaruma::Init()
{
	m_x = 416.0f;
	m_y = 32.0f;

	w_ran = 0;

	m_vx = 0.0f;
	m_vy = 0.0f;

	//壁情報記憶用
	w_m_up = false;
	w_m_down = false;
	w_m_left = false;
	w_m_right = false;

	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_YUKIDARUMA, 1);
}

//アクション
void CObjYukidaruma::Action()
{
	//壁情報を記録
	//上
	if (m_hit_up = true) {
		w_m_up = true;
	}
	else if (m_hit_up = false) {
		w_m_up = false;
	}

	//下
	if (m_hit_down = true) {
		w_m_down = true;
	}
	else if (m_hit_down = false) {
		w_m_down = false;
	}

	//左
	if (m_hit_left = true) {
		w_m_left = true;
	}
	else if (m_hit_left = false) {
		w_m_left = false;
	}

	//右
	if (m_hit_right = true) {
		w_m_right = true;
	}
	else if (m_hit_right = false) {
		w_m_right = false;
	}


	//壁との衝突でランダムに方向転換する
	if (w_m_up == true && w_m_down == true && w_m_right == true && w_m_left == true) {
		m_y;
		m_x++;
	}

	////HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//雪だるまが領域外に行かない処理
	if (m_x + 32.0f > 800.0f) {
		m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f) {
		m_y = 600.0f - 32.0f;
	}
	if (m_y < 0.0f) {
		m_y = 0.0f;
	}
	if (m_x < 0.0f) {
		m_x = 0.0f;
	}

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
void CObjYukidaruma::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}