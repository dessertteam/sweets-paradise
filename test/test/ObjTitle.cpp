#include"GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"
#include "GameL\DrawTexture.h"

#include"GameHead.h"
#include"ObjTitle.h"

//使用するねネームスペース
using namespace GameL;

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
}

//アクション
void CObjTitle::Action()
{
	//エンターキーを押してシーン:ゲームメインに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}

	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー
void CObjTitle::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src1;//描画元切り取り位置
	RECT_F dst1;//描画先表示位置

	RECT_F src2;//描画元切り取り位置
	RECT_F dst2;//描画先表示位置

	RECT_F src3;//描画元切り取り位置
	RECT_F dst3;//描画先表示位置

	RECT_F src4;//描画元切り取り位置
	RECT_F dst4;//描画先表示位置

				//切り取り位置の設定
	src1.m_top = 30.0f;
	src1.m_left = 5.0f;
	src1.m_right = 336.0f;
	src1.m_bottom = 63.0f;

	//切り取り位置の設定
	src2.m_top = 74.0f;
	src2.m_left = 5.0f;
	src2.m_right = 508.0f;
	src2.m_bottom = 105.0f;

	//切り取り位置の設定
	src3.m_top = 238.0f;
	src3.m_left = 5.0f;
	src3.m_right = 508.0f;
	src3.m_bottom = 274.0f;

	//切り取り位置の設定
	src4.m_top = 283.0f;
	src4.m_left = 5.0f;
	src4.m_right = 508.0f;
	src4.m_bottom = 315.0f;

	//表示位置の設定
	dst1.m_top = 100.0f;
	dst1.m_left = 100.0f;
	dst1.m_right = 700.0f;
	dst1.m_bottom = 200.0f;

	//表示位置の設定
	dst2.m_top = 370.0f;
	dst2.m_left = 170.0f;
	dst2.m_right = 620.0f;
	dst2.m_bottom = 440.0f;

	//表示位置の設定
	dst3.m_top = 500.0f;
	dst3.m_left = 25.0f;
	dst3.m_right = 410.0f;
	dst3.m_bottom = 530.0f;

	//表示位置の設定
	dst4.m_top = 500.0f;
	dst4.m_left = 415.0f;
	dst4.m_right = 790.0f;
	dst4.m_bottom = 530.0f;

	Draw::Draw(3, &src1, &dst1, c, 0.0f);
	Draw::Draw(3, &src2, &dst2, c, 0.0f);
	Draw::Draw(3, &src3, &dst3, c, 0.0f);
	Draw::Draw(3, &src4, &dst4, c, 0.0f);

	//Font::StrDraw(L"SweetParadise", 150, 100, 70, c);
	//Font::StrDraw(L"GameStart:Push EnterKey", 210, 400, 30, c);
	//Font::StrDraw(L"操作方法　十字キー：移動　Zキー：スタート位置に戻る", 25, 500, 30, c);
}