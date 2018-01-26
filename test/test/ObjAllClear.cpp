//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjAllClear::Init()
{

}

//アクション
void CObjAllClear::Action()
{

	//エンターキーを押してシーン:タイトルに移行する
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
void CObjAllClear::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //切り取り位置の設定
	src.m_top = 113.0f;
	src.m_left = 5.0f;
	src.m_right = 508.0f;
	src.m_bottom = 146.0f;

	//表示位置の設定
	dst.m_top = 240.0f;
	dst.m_left = 250.0f;
	dst.m_right = 850.0f;
	dst.m_bottom = 300.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);

	//Font::StrDraw(L"GameClear", 300, 250, 50, c);
}