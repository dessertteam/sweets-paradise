#pragma once
//使用するヘッダー
#include"GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン:ゲームタイトル
class CSceneGameOver :public CScene
{
public:
	CSceneGameOver();
	~CSceneGameOver();
	void InitScene();//ゲームタイトルの初期化
	void Scene();//ゲームタイトルの実行中メソッド
private:

};