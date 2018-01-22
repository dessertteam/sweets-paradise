//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//使用するヘッダー
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"

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
	//マップ情報
	int map[19][25] =
	{
		{ 7,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6 ,6,6,6,6 ,6,9 },
		{ 1,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0 ,0,0,0,0 ,0,1 },
		{ 1,0,7 ,6,6,0,6,12,6,0,6,6,6 ,0,6,6,6,12,6 ,0,6,6,9 ,0,1 },
		{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,0 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
		{ 1,0,1 ,0,2,3,0,1 ,0,23,30,0,1 ,0,38,17,0,1 ,0 ,25,39,0,1 ,0,1 },
		{ 1,0,0 ,0,5,4,0,1 ,0,16,37,0,1 ,0,24,31,0,1 ,0 ,18,32,0,0 ,0,1 },
		{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
		{ 1,0,8 ,6,9,0,6,11,6,6,6,6,11,6,6,6,0,8 ,9 ,0,7,6,10,0,1 },
		{ 1,0,0 ,0,1,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,1 ,0,1,0,0 ,0,1 },
		{ 0,0,1 ,0,1,0,1,0 ,6,6,6,6,6 ,6,6,6,6,0 ,0 ,0,1,0,1 ,0,0 },
		{ 1,0,1 ,0,0,0,1,0 ,0,0,0,0,0 ,0,0,0,0,0 ,1 ,0,0,0,1 ,0,1 },
		{ 1,0,14,6,6,0,8,12,6,0,6,6,12,6,6,0,6,12,10,0,6,6,13,0,1 },
		{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
		{ 1,0,0 ,0,33,40,0,0 ,0,41,20,0,1 ,0,35,21,0,1 ,0 ,22,29,0,0 ,0,1 },
		{ 1,0,1 ,0,26,19,0,1 ,0,34,27,0,1 ,0,42,28,0,1 ,0 ,36,43,0,1 ,0,1 },
		{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,0 ,0 ,0,0,0,1 ,0,1 },
		{ 1,0,8 ,6,6,0,6,11,6,6,6,6,10,0,6,6,6,6 ,6 ,0,6,6,10,0,1 },
		{ 1,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0 ,0,0,0,0 ,0,1 },
		{ 8,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6 ,6,6,6,6 ,6,10 },

	};

	/*int map[19][25] =
	{
	{ 7,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6 ,6,6,6,6 ,6,9 },
	{ 1,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0 ,0,0,0,0 ,0,1 },
	{ 1,0,7 ,6,6,0,6,12,6,0,6,6,6 ,0,6,6,6,12,6 ,0,6,6,9 ,0,1 },
	{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,0 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
	{ 1,0,1 ,0,7,9,0,1 ,0,7,9,0,1 ,0,7,9,0,1 ,0 ,7,9,0,1 ,0,1 },
	{ 1,0,0 ,0,8,10,0,1 ,0,8,10,0,1 ,0,8,10,0,1 ,0 ,8,10,0,0 ,0,1 },
	{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
	{ 1,0,8 ,6,9,0,6,11,6,6,6,6,11,6,6,6,0,8 ,9 ,0,7,6,10,0,1 },
	{ 1,0,0 ,0,1,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,1 ,0,1,0,0 ,0,1 },
	{ 0,0,1 ,0,1,0,1,0 ,6,6,6,6,6 ,6,6,6,6,0 ,0 ,0,1,0,1 ,0,0 },
	{ 1,0,1 ,0,0,0,1,0 ,0,0,0,0,0 ,0,0,0,0,0 ,1 ,0,0,0,1 ,0,1 },
	{ 1,0,14,6,6,0,8,12,6,0,6,6,12,6,6,0,6,12,10,0,6,6,13,0,1 },
	{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0 ,0,0,0,1 ,0,1 },
	{ 1,0,0 ,0,7,9,0,0 ,0,7,9,0,1 ,0,7,9,0,1 ,0 ,7,9,0,0 ,0,1 },
	{ 1,0,1 ,0,8,10,0,1 ,0,8,10,0,1 ,0,8,10,0,1 ,0 ,8,10,0,1 ,0,1 },
	{ 1,0,1 ,0,0,0,0,1 ,0,0,0,0,1 ,0,0,0,0,0 ,0 ,0,0,0,1 ,0,1 },
	{ 1,0,8 ,6,6,0,6,11,6,6,6,6,10,0,6,6,6,6 ,6 ,0,6,6,10,0,1 },
	{ 1,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0,0,0,0,0 ,0 ,0,0,0,0 ,0,1 },
	{ 8,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6,6,6,6,6 ,6 ,6,6,6,6 ,6,10 },

	};*/

	//マップデータ情報
	int block[19][25] =
	{
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1 },
		{ 1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,0,1 },
		{ 1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1 },
		{ 0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,0 },
		{ 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,1 },
		{ 1,0,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1 },
		{ 1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1 },
		{ 1,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1 },
		{ 1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },

	};

	//Font作成
	Font::SetStrTex(L"0123456789秒");

	//外部グラフィックファイルを読み込み0番に登録(512*512ピクセル)
	Draw::LoadImage(L"character.png", 0, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み1番に登録(512*512ピクセル)
	Draw::LoadImage(L"block.png", 1, TEX_SIZE_512);

	//外部グラフィックファイルを読み込み2番に登録(512*512ピクセル)
	Draw::LoadImage(L"house.png", 2, TEX_SIZE_512);

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();		//主人公オブジェクト作成
	Objs::InsertObj(obj, OBJ_HERO, 10);	//作った主人公オブジェクトをオブジェクトマネージャーに登録

										//blockオブジェクト作成
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 8);

	//穴オブジェクト作成
	CObjhole* objh = new CObjhole();
	Objs::InsertObj(objh, OBJ_HOLE, 9);

	//雪だるまオブジェクト作成
	CObjYukidaruma* obj_yukidaruma = new CObjYukidaruma();  //雪だるまオブジェクト作成
	Objs::InsertObj(obj_yukidaruma, OBJ_YUKIDARUMA, 10);     //作った雪だるまオブジェクトをオブジェクトマネージャーに登録

															 //クリキントンオブジェクト作成
	CObjKuri* obj_kuri = new CObjKuri(); //クリキントンオブジェクト作成
	Objs::InsertObj(obj_kuri, OBJ_KURI, 10); //作ったクリキントンオブジェクトをオブジェクトマネージャーに登録

											 //Test用 敵オブジェクト作成
	CObjFEnemy* obje = new CObjFEnemy(600, 500);
	Objs::InsertObj(obje, OBJ_FENEMY, 10);

	//敵(ドーナツ)オブジェクト作成
	CObjSymmetry* objd = new CObjSymmetry(); //敵(ドーナツ)オブジェクト作成
	Objs::InsertObj(objd, OBJ_SYMMETRY, 10); //作った敵(ドーナツ)オブジェクトをオブジェクトマネージャーに登録

											 //タイムオブジェクト作成
	CObjTime* objt = new CObjTime();
	Objs::InsertObj(objt, OBJ_TIME, 11);
}

//ゲームメインの実行中メソッド
void CSceneMain::Scene()
{

}