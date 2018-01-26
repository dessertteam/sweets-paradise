//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneGameOver.h"
#include"GameHead.h"
#include "GameL\Audio.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}

//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}

//ゲームメイン初期化
void CSceneGameOver::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"ゲームオーバー(仮1).wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.5 - v));

	//音楽スタート
	Audio::Start(0);

	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME OVER");

	//外部グラフィックファイルを読み込み3番に登録(512*512ピクセル)
	Draw::LoadImage(L"char.png", 3, TEX_SIZE_512);

	//ゲームオーバーオブジェクト作成
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

}

void CSceneGameOver::Scene()
{

}