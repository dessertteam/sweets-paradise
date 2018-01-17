//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTime.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjTime::Init()
{
	m_time = 3600;
	m_time2 = 0;
	m_time3 = 0;
	m_flag_time = false;
}

//アクション
void CObjTime::Action()
{
	m_time--;
	m_time2++;
	m_time3++;

	if (m_time2>1800)
	{
		m_time2 = 0;
		CObjYukidaruma* obj_yukidaruma = new CObjYukidaruma();  //雪だるまオブジェクト作成
		Objs::InsertObj(obj_yukidaruma, OBJ_YUKIDARUMA, 10);     //作った雪だるまオブジェクトをオブジェクトマネージャーに登録

		CObjSymmetry* objd = new CObjSymmetry(); //敵(ドーナツ)オブジェクト作成
		Objs::InsertObj(objd, OBJ_SYMMETRY, 10); //作った敵(ドーナツ)オブジェクトをオブジェクトマネージャーに登録
	}

	if (m_time3 > 900)
	{
		m_time3 = 0;

		CObjFEnemy* obje = new CObjFEnemy(600, 500);//おばけ
		Objs::InsertObj(obje, OBJ_FENEMY, 10);//おばけ
	}

	if (m_time < 0)
	{
		Scene::SetScene(new CSceneClear());
	}
}

//ドロー
void CObjTime::Draw()
{
	//m_timeから秒を求める
	int second;//秒

	second = (m_time / 60) % 60;//秒

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"%d", second);//秒の値を文字列化
	Font::StrDraw(str, 10, 10, 20, c);
}