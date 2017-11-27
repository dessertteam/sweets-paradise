//使用ヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjHero.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHero::Init()
{
	m_x = 0;
	m_y = 0;
	m_speed = 3.0f;
}

//アクション
void CObjHero::Action()
{
	//主人公(蟻)の移動
	if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_x += m_speed;
	}

	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_x -= m_speed;
	}
	if (Input::GetVKey(VK_UP) == true)
	{
		m_y -= m_speed;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		m_y += m_speed;
	}

	//初期位置(予定)に戻る
	if (Input::GetVKey('Z') == true)
	{
		m_x = 360.0f;
		m_y = 520.0f;
	}

	//主人公(蟻)が領域外に行かない処理
	if (m_x + 64.0f > 800.0f)
	{
		m_x = 800.0f - 64.0f;
	}
	if (m_y + 64.0f > 600.0f)
	{
		m_y = 600.0f - 64.0f;
	}
	if (m_y < 0.0f)
	{
		m_y = 0.0f;
	}
	if (m_x < 0.0f)
	{
		m_x = 0.0f;
	}
}

//ドロー
void CObjHero::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 512.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = 0.0f + m_y;
	dst.m_left = 0.0f + m_x;
	dst.m_right = 64.0f + m_x;
	dst.m_bottom = 64.0f + m_y;

	Draw::Draw(0, &src, &dst, c, 0.0f);
}