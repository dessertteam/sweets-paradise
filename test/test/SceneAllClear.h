#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーン : クリア
class CSceneAllClear :public CScene
{
public:
	CSceneAllClear();
	~CSceneAllClear();
	void InitScene();//初期化メソッド
	void Scene();	 //実行中メソッド
private:
};