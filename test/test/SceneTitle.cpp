//STLデバッグ機能をOFFにする
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameLで使用するヘッダー
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include"SceneMain.h"
#include"GameHead.h"


//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"SweetParadise");
	Font::SetStrTex(L"GameStart");

	/*
	//音楽情報の読み込み
	Audio::LoadAudio(0, L"タイトル(仮3).wav", SOUND_TYPE::BACK_MUSIC);

	//ミュージックスタート
	float Volume = Audio::VolumeMaster(1.5f);//マスターボリュームを1.0にする
	Audio::Start(0);//音楽スタート*/

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();//タイトルオブジェクト
	Objs::InsertObj(obj, OBJ_TITLE, 10);//主人公オブジェクト
}

void CSceneTitle::Scene()
{

}