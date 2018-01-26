//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"
#include "GameL\Audio.h"

//コンストラクタ
CSceneAllClear::CSceneAllClear()
{

}

//デストラクタ
CSceneAllClear::~CSceneAllClear()
{

}

//初期化メソッド
void CSceneAllClear::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"完全クリア.wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.4 - v));

	//音楽スタート
	Audio::Start(0);

	Font::SetStrTex(L"GameClear");

	//外部グラフィックファイルを読み込み3番に登録(512*512ピクセル)
	Draw::LoadImage(L"char.png", 3, TEX_SIZE_512);

	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();		//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);	//クリアオブジェクト登録

}

//実行中メソッド
void CSceneAllClear::Scene()
{


}