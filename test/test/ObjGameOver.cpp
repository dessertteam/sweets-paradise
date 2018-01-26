#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{

}

//アクション
void CObjGameOver::Action()
{
	//エンターキーを押してシーン:ゲームTitlleに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}
}
//ドロー
void CObjGameOver::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src1;//描画元切り取り位置
	RECT_F dst1;//描画先表示位置

	RECT_F src2;//描画元切り取り位置
	RECT_F dst2;//描画先表示位置

				//切り取り位置の設定
	src1.m_top = 155.0f;
	src1.m_left = 5.0f;
	src1.m_right = 508.0f;
	src1.m_bottom = 188.0f;

	//切り取り位置の設定
	src2.m_top = 198.0f;
	src2.m_left = 5.0f;
	src2.m_right = 508.0f;
	src2.m_bottom = 230.0f;

	//表示位置の設定
	dst1.m_top = 240.0f;
	dst1.m_left = 250.0f;
	dst1.m_right = 850.0f;
	dst1.m_bottom = 300.0f;

	//表示位置の設定
	dst2.m_top = 420.0f;
	dst2.m_left = 230.0f;
	dst2.m_right = 830.0f;
	dst2.m_bottom = 470.0f;

	Draw::Draw(3, &src1, &dst1, c, 0.0f);
	Draw::Draw(3, &src2, &dst2, c, 0.0f);

	//Font::StrDraw(L"GameOver", 300, 250, 50, c);
	//Font::StrDraw(L"Push   EnterKey", 300, 400, 30, c);
}