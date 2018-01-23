//STLデバック機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneClear.h"
#include "GameHead.h"
#include "GameL\Audio.h"

//コンストラクタ
CSceneClear::CSceneClear()
{

}

//デストラクタ
CSceneClear::~CSceneClear()
{

}

//初期化メソッド
void CSceneClear::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"ゲームクリア(仮2).wav", BACK_MUSIC);

	//ボリュームを1.0に戻す
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//音楽スタート
	Audio::Start(0);


	//クリアオブジェクト作成
	CObjClear* obj = new CObjClear();		//クリアオブジェクト作成
	Objs::InsertObj(obj, OBJ_CLEAR, 10);	//クリアオブジェクト登録
}

//実行中メソッド
void CSceneClear::Scene()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GameClear", 300, 250, 50, c);
	Font::StrDraw(L"Push   EnterKey", 300, 400, 30, c);
}