//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include"GameL\HitBoxManager.h"
#include"GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjFEnemy.h"
#include"SceneMain.h"
#include"UtilityModule.h"

//ランダム用ヘッダー
#include <stdlib.h>
#include <time.h>

//使用するネームスペース
using namespace GameL;
CObjFEnemy::CObjFEnemy(float x, float y)
{
	m_x = x;
	m_y = y;
}

//イニシャライズ
void CObjFEnemy::Init()
{
	m_x = 96.0f;
	m_y = 480.0f;
	m_vx = 0.0f;
	m_vy = 0.0f;

	m_mx = +1;
	m_my = 0;

	m_direc = 1;

	memo = 1;

	w_ranif = 0;
	srand(unsigned(time(NULL)));//ランダム情報を初期化
	w_ranif = rand() % 3 + 1;

	//移動ベクトルの正規化
	UnitVec(&m_vy, &m_vx);

	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_ENEMY, OBJ_FENEMY, 1);
}
float r = 0.0f;
//アクション
void CObjFEnemy::Action()
{
	/*//アリと敵の角度を取る
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

	if (ar < br)
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
	}
	UnitVec(&m_vx, &m_vy);
	}
	m_px += m_vx*2.0f;
	m_py += m_vy*2.0f;*/

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

	/*
	//お化けが領域外に行かない処理
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
	}*/

	//ブロックタイプ検知用の変数がないためのためのダミー
	int d;

	//ブロックとの当たり判定実行
	CObjBlock*pb = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	pb->BlockHit(
		&m_x, &m_y,
		&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
		&m_vx, &m_vy, &d
	);

	//敵のHitBox更新用ポインター取得
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_x, m_y);            //HitBoxの位置を敵の位置に更新

									  //位置の更新
	m_x += m_vx;
	m_y += m_vy;
}

//ドロー
void CObjFEnemy::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 128.0f;
	src.m_left = 64.0f;
	src.m_right = 0.0f;
	src.m_bottom = 192.0f;

	//ブロック情報を持ってくる
	CObjBlock* block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}