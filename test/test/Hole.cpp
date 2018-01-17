#include "Hole.h"
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjHero.h"

bool flag;

//コンストラクタ
Hole::Hole()
{
}

//デストラクタ
Hole::~Hole()
{
}
//イニシャライズ
 void Hole::Init()
{

}
 //アクション
 void Hole::Action()
 {
	 if (Input::GetVKey('Z') == true)
	 {
		 flag = true;

		 float GetX();
		 float GetY();

		 
	 }
	 else
	 {
		 flag = false;
	 }
 }

 //ドロー
 void Hole::Draw()
 {
	
	 //描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	 float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	 RECT_F src;//描画元切り取り位置
	 RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	 src.m_top = 128.0f;
	 src.m_left = 128.0f;
	 src.m_right = 192.0f;
	 src.m_bottom = 192.0f;

	 //表示位置の設定
	 dst.m_top = 0.0f + m_y;
	 dst.m_left = 0.0f + m_x;
	 dst.m_right = 32.0f + m_x;
	 dst.m_bottom = 32.0f + m_y;

	 if (flag == true)
	 {
		 Draw::Draw(0, &src, &dst, c, 0.0f);
	 }
 }
