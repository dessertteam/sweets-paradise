//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjBlock.h"
#include "UtilityModule.h"


//使用するネームスペース
using namespace GameL;

//マップ表示
CObjBlock::CObjBlock(int map[19][25])
{
	memcpy(m_map, map, sizeof(int)*(19 * 25));
}

//イニシャライズ
void CObjBlock::Init()
{

}

//アクション
void CObjBlock::Action()
{
	//主人公(蟻)の位置を取得

	//主人公と角度を取る
	CObjHero*obj = (CObjHero*)Objs::GetObj(OBJ_HERO);

	//敵(雪だるま）と角度を取る
	CObjYukidaruma*obj_yukidaruma = (CObjYukidaruma*)Objs::GetObj(OBJ_YUKIDARUMA);

	//敵（先回り）と角度を取る
	CObjFEnemy*obj_fenemy = (CObjFEnemy*)Objs::GetObj(OBJ_FENEMY);
	
}

//ドロー
void CObjBlock::Draw()
{
	
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//背景表示
	src.m_top = 256.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*32.0f;
				dst.m_left = j*32.0f;
				dst.m_right = dst.m_left + 32.0f;
				dst.m_bottom = dst.m_top + 32.0f;

				if (m_map[i][j] == 2)
				{
					//家1
					BlockDrawHouse(0.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 3)
				{
					//家2
					BlockDrawHouse(0.0f, 128.0f, &dst, c);
				}
				else if (m_map[i][j] == 4)
				{
					//家3
					BlockDrawHouse(0.0f, 256.0f, &dst, c);
				}
				else if (m_map[i][j] == 5)
				{
					//家4
					BlockDrawHouse(0.0f, 384.0f, &dst, c);
				}
				else if (m_map[i][j] == 6)
				{
					//横ブロック
					BlockDraw(0.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j] == 7)
				{
					//左上L字
					BlockDraw(64.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 8)
				{
					//左下L字
					BlockDraw(64.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j] == 9)
				{
					//右上L字
					BlockDraw(128.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 10)
				{
					//右下L字
					BlockDraw(128.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j] == 11)
				{
					//上T字
					BlockDraw(192.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j] == 12)
				{
					//下T字
					BlockDraw(192.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 13)
				{
					//左T字
					BlockDraw(256.0f, 64.0f, &dst, c);
				}
				else if (m_map[i][j] == 14)
				{
					//右T字
					BlockDraw(256.0f, 0.0f, &dst, c);
				}
				else if (m_map[i][j] == 15)
				{
					//十字
					BlockDraw(320.0f, 0.0f, &dst, c);
				}
				else
				{
					//縦ブロック
					BlockDraw(0.0f, 0.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawMethod関数
//引数1	float x		:リソース切り取り位置X
//引数2	float y		:リソース切り取り位置Y
//引数3 RECT_F* dst :描画位置
//引数4 float c[]	:カラー情報
//ブロックを64*64限定描画用。リソース切り取り位置のみx・yで
//設定できる
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//描画
	Draw::Draw(1, &src, dst, c, 0.0f);
}

//BlockDrawHouseMethod関数
//引数1	float x		:リソース切り取り位置X
//引数2	float y		:リソース切り取り位置Y
//引数3 RECT_F* dst :描画位置
//引数4 float c[]	:カラー情報
//ブロックを128*128限定描画用。リソース切り取り位置のみx・yで
//設定できる
void CObjBlock::BlockDrawHouse(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 128.0f;
	src.m_bottom = src.m_top + 128.0f;
	//描画
	Draw::Draw(2, &src, dst, c, 0.0f);
}
//BlockHit関数
//引数1		float*	x		:判定を行うobjectのX位置
//引数2		float*	y		:判定を行うobjectのY位置
//引数4		bool*	up		:上下左右判定の上部分に当たっているかどうかを返す
//引数5		bool*	down	:上下左右判定の下部分に当たっているかどうかを返す
//引数6		bool*	left	:上下左右判定の左部分に当たっているかどうかを返す
//引数7		bool*	right	:上下左右判定の右部分に当たっているかどうかを返す
//引数8		float*	vx		:左右判定時の反発による移動方向・力の値を変えて返す
//引数9		float*	vy		:上下判定時による自由落下運動の移動方向・力の値を変えて返す
//引数10	int*	bt		:下部分判定時、特殊なブロックのタイプを返す
//判定を行うobjectとブロック32*32限定で、当たり判定と上下左右を行う
//その結果は引数4～10に返す
void CObjBlock::BlockHit(
	float* x, float* y,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy, int* bt
)
{
	//主人公の衝突状態確認用フラグの初期化
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//踏んでいるblockの種類の初期化
	*bt = 0;

	//m_mapの全要素にアクセス
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_map[i][j] > 0)
			{
				//要素番号を座標に変更
				float bx = j*32.0f;
				float by = i*32.0f;

				//主人公(蟻)とブロックの当たり判定
				if ((*x + 32.0f > bx) && (*x < bx + 32.0f) && (*y + 32.0f > by) && (*y < by + 32.0f))
				{
					//上下左右判定

					//vectorの作成
					float rvx = *x - bx;
					float rvy = *y - by;

					//長さを求める
					float len = sqrt(rvx*rvx + rvy*rvy);

					//角度を求める
					float r = atan2(rvy, rvx);
					r = r*180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					//lenがある一定の長さより短い場合判定に入る
					if (len < 43.0f)
					{
						//角度で上下左右を判定
						if ((r < 45 && r >= 0) || r > 315)
						{
							//右
							*right = true;//主人公の左の部分が衝突している
							*x = bx + 32.0f;//ブロックの位置+主人公の幅
							-(*vx)*0.1f;//-VX*反発係数

						}
						if (r > 45 && r < 135)
						{
							//上
							*down = true;//主人公の下の部分が衝突している
							*y = by - 32.0f;//ブロックの位置-主人公の幅
							-(*vy)*0.1f;
						}
						if (r > 135 && r < 225)
						{
							//左
							*left = true;//主人公の右の部分が衝突している
							*x = bx - 32.0f;//ブロックの位置-主人公の幅
							-(*vx)*0.1f;//-VX*反発係数 -(*vx)*0.1f;
						}
						if (r > 225 && r < 315)
						{
							//下
							*up = true;//主人公の上の部分が衝突している
							*y = by + 32.0f;//ブロックの位置+主人公の幅
							if (*vy < 0)
							{
								-(*vy)*0.1f;
							}
						}
					}
				}
			}
		}
	}
}