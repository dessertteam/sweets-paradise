//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "UtilityModule.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{
	
}

//ゲームメインの初期化メソッド
void CSceneMain::InitScene()
{
	//外部グラフィックファイルを読み込み0番に登録(512*512ピクセル)
	Draw::LoadImage(L"character.png", 0, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();		//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);	//作った主人公オブジェクトをオブジェクトマネージャーに登録

	//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//雪だるまオブジェクト作成
	CObjYukidaruma* obj_yukidaruma = new CObjYukidaruma();  //雪だるまオブジェクト作成
	Objs::InsertObj(obj_yukidaruma, OBJ_YUKIDARUMA, 10);     //作った雪だるまオブジェクトをオブジェクトマネージャーに登録

	 //Test用 敵オブジェクト作成
	CObjFEnemy* obje = new CObjFEnemy(600, 500);
	Objs::InsertObj(obje, OBJ_FENEMY, 10);

	//敵(ドーナツ)オブジェクト作成
	CObjSymmetry* objd = new CObjSymmetry(); //敵(ドーナツ)オブジェクト作成
	Objs::InsertObj(objd, OBJ_SYMMETRY, 10); //作った敵(ドーナツ)オブジェクトをオブジェクトマネージャーに登録

}

//ゲームメインの実行中メソッド
void CSceneMain::Scene()
{
	//マップを数値化する処理です。
	//うまくいかなかったのでとりあえずコメント

	//CObjBlock map2;
	//CObjHero h1;
	//int x, y;
	//x = h1.GetX();
	//y = h1.GetY();
	//Searching(map2.m_map,x/32,y/32, 10);

}