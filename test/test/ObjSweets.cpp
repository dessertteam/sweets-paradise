//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjSweets.h"

//使用するネームスペース
using namespace GameL;

//マップ表示
CObjSweets::CObjSweets(int block[19][25])
{
	memcpy(m_block, block, sizeof(int)*(19 * 25));
}

//イニシャライズ
void CObjSweets::Init()
{
	//当たり判定用HitBoxを作成
	Hits::SetHitBox(this, m_x, m_y, 32, 32, ELEMENT_SWEETS, OBJ_SWEETS, 1);
}

//アクション
void CObjSweets::Action()
{

}

//ドロー
void CObjSweets::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			if (m_block[i][j] > 0)
			{
				//表示位置の設定
				dst.m_top = i*32.0f + 6;
				dst.m_left = j*32.0f + 4;
				dst.m_right = dst.m_left + 24.0f;
				dst.m_bottom = dst.m_top + 24.0f;

				if (m_block[i][j] == 2)
				{
					//家1:2+16～22
					BlockDrawHouse(0.0f, 0.0f, &dst, c);
				}
				else if (m_block[i][j] == 3)
				{
					//家2:3+23～29
					BlockDrawHouse(0.0f, 128.0f, &dst, c);
				}
				else if (m_block[i][j] == 4)
				{
					//家3:4+30～36
					BlockDrawHouse(0.0f, 256.0f, &dst, c);
				}
				else if (m_block[i][j] == 5)
				{
					//家4:5+37～43
					BlockDrawHouse(0.0f, 384.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawHouseMethod関数
//引数1	float x		:リソース切り取り位置X
//引数2	float y		:リソース切り取り位置Y
//引数3 RECT_F* dst :描画位置
//引数4 float c[]	:カラー情報
//ブロックを128*128限定描画用。リソース切り取り位置のみx・yで
//設定できる
void CObjSweets::BlockDrawHouse(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 128.0f;
	src.m_bottom = src.m_top + 128.0f;
	//描画
	Draw::Draw(2, &src, dst, c, 0.0f);
}
