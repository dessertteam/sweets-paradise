//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameHead.h"
#include "Objhole.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjhole::Init()
{
	m_x = 416.0f;
	m_y = 544.0f;
}

//アクション
void CObjhole::Action()
{

}

//ドロー
void CObjhole::Draw()
{

	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 128.0f;
	src.m_left = 192.0f;
	src.m_right = 128.0f;
	src.m_bottom = 192.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 32.0f + m_x;
	dst.m_right = 0.0f + m_x;
	dst.m_bottom = 32.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}