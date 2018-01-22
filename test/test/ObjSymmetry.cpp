//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSymmetry.h"
#include "GameL\HitBoxManager.h"
#include <math.h>

//ランダム用ヘッダー
#include <stdlib.h>
#include <time.h>

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSymmetry::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_x = 96.0f;
	m_y = 96.0f;

	m_mx = 2;
	m_my = 0;

	m_direc = 1;

	memo = 2;

	m_ani_time = 0;
	m_ani_frame = 0;	//静止フレームを初期にする

	m_ani_max_time = 1800;//アニメーション間隔幅

	w_ranif = 0;

	srand(unsigned(time(NULL)));//ランダム情報を初期化
	w_ranif = rand() % 3 + 1;


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
	/*
	//領域外に出ない処理
	if (m_x + 32.0f > 800.0f)
	{
	m_x = 800.0f - 32.0f;
	}
	if (m_y + 32.0f > 600.0f)
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
	*/

	//初期位置からの移動
	//左から判断していく
	//[2][2]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 32 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 32 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][6]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][10]
	//パターン1
	//下に
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 288 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 288 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][14]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 3 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 3 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}


	//[2][20]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 32) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[2][24]
	//下に
	if (m_direc == 1 && m_x == 736 && m_y == 32) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 2 && m_x == 736 && m_y == 32) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[4][4]
	//パターン1
	//右に
	if (m_direc == 2 && m_x == 96 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 0 && m_x == 96 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][6]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][7]
	//パターン1
	//左に
	if (m_direc == 2 && m_x == 192 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 1 && m_x == 192 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][9]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 256 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 256 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][10]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 288 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 288 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][12]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 3 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 352 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 352 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 3 + 1;
	}

	//▼[4][14]
	//パターン1
	//下に
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//上に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//パターン4
	//下に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 3 && m_x == 416 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][17]
	//パターン1
	//左に
	if (m_direc == 2 && m_x == 512 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 3 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 1 && m_x == 512 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
	}

	//[4][19]
	//パターン1
	//右に
	if (m_direc == 2 && m_x == 576 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 0 && m_x == 576 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[4][20]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 96) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[4][22]
	//パターン1
	//左に
	if (m_direc == 2 && m_x == 672 && m_y == 96) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//下に
	else if (m_direc == 1 && m_x == 672 && m_y == 96) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][2]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//上に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//下に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//▼[6][4]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//上に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//左に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 96 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 96 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][22]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 672 && m_y == 160) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 672 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[6][24]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 160) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 160) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}

	//[7][4]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 96 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 96 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][6]
	//パターン1
	//左に
	else if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][7]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 192 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 192 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[7][9]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 256 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 256 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][12]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 352 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 352 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[7][14]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 416 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 416 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][17]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[7][19]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 576 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 576 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][20]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 192) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[7][22]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 672 && m_y == 192) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 672 && m_y == 192) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][2]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[9][4]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 96 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 96 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][6]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[9][8]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 224 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 224 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][17]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][18]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 544 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 544 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[9][22]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 672 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 672 && m_y == 256) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[9][24]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 256) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 256) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][0]
	if (m_x == -32 && m_y == 288 && m_direc == 0)
	{
		m_x = 800; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[10][2]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][18]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 544 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 544 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][20]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 288) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][24]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 288) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 288) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[10][25]
	if (m_x == 832 && m_y == 288 && m_direc == 1)
	{
		m_x = -32; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][4]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 96 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 96 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][6]
	//パターン1
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[11][8]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 224 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 224 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][10]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 288 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 288 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][16]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 480 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 480 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[11][18]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 544 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 544 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[11][20]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 320) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 320) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[11][22]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 672 && m_y == 320) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 672 && m_y == 320) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][4]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 96 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 96 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][6]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][7]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 192 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 192 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][9]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 256 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 256 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][10]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 288 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 288 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][12]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 352 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 352 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][14]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 416 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 416 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][16]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 480 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 480 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][17]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 512 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 512 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[13][19]
	//パターン1
	//下に
	if (m_direc == 0 && m_x == 576 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && m_x == 576 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][20]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 384) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[13][22]
	//パターン1
	//下に
	if (m_direc == 1 && m_x == 672 && m_y == 384) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && m_x == 672 && m_y == 384) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[14][2]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 32 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 32 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][4]
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 96 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 96 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][7]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 192 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 192 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][9]
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 256 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 256 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][22]
	//パターン1
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 672 && m_y == 416) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 672 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[14][24]
	//上に
	if (m_direc == 1 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 736 && m_y == 416) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 736 && m_y == 416) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[16][4]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 96 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 96 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][6]
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 160 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 160 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][7]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 192 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 192 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[16][9]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 256 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 256 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][12]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 352 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 352 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[16][14]
	//上に
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//右に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}

	//[16][17]
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 512 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 512 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][19]
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 576 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 576 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][20]
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//下に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = 0; m_my = memo; m_direc = 3;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 2 && w_ranif == 1 && m_x == 608 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 2 && w_ranif == 2 && m_x == 608 && m_y == 480) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[16][22]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 672 && m_y == 480) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 672 && m_y == 480) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	//[18][2]
	//パターン1
	//上に
	if (m_direc == 0 && m_x == 32 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 3 && m_x == 32 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][6]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 160 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 160 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][14]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 416 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 416 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][20]
	//パターン1
	//左に
	if (m_direc == 0 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 0 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//右に
	else if (m_direc == 1 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}
	//上に
	else if (m_direc == 1 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン3
	//左に
	else if (m_direc == 3 && w_ranif == 1 && m_x == 608 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}
	//右に
	else if (m_direc == 3 && w_ranif == 2 && m_x == 608 && m_y == 544) {
		m_mx = memo; m_my = 0; m_direc = 1;
		w_ranif = rand() % 2 + 1;
	}

	//[18][24]
	//パターン1
	//上に
	if (m_direc == 1 && m_x == 736 && m_y == 544) {
		m_mx = 0; m_my = -memo; m_direc = 2;
		w_ranif = rand() % 2 + 1;
	}
	//パターン2
	//左に
	else if (m_direc == 3 && m_x == 736 && m_y == 544) {
		m_mx = -memo; m_my = 0; m_direc = 0;
		w_ranif = rand() % 2 + 1;
	}

	m_x += m_mx;
	m_y += m_my;
	m_ani_time += 1;


	/*
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

	*/

	if (m_ani_time > 1800)
		memo = 4.0f;

	//栗のアニメーション？
	if (m_ani_time > m_ani_max_time)
	{
		m_ani_frame += 1;
		m_ani_time = 0;
	}

	if (m_ani_frame == 4)
	{
		m_ani_frame = 0;
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

	//HitBoxの内容を更新
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);

	//位置の更新
	m_x += m_vx;
	m_y += m_vy;
}

//ドロー
void CObjSymmetry::Draw()
{
	int AniData[10] =
	{
		0,1,0,1,
	};

	//描画カラー情報
	float c[4] = { 1.0f, 1.0f, 0.0f, 1.0f };

	RECT_F src;
	RECT_F dst;

	//切り取り位置の設定
	src.m_top = 64.0f;
	src.m_left = 0.0f + AniData[m_ani_frame] * 64;
	src.m_right = 64.0f + AniData[m_ani_frame] * 64;
	src.m_bottom = 128.0f;
	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 32.0f + m_x;
	dst.m_bottom = 32.0f + m_y;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}