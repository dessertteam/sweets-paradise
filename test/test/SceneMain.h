#pragma once
//使用するヘッダー
#include "GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 主人公
class CSceneMain : public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();	//ゲームメインの初期化メソッド
	void Scene();		//ゲームメインの実行中メソッド
private:
	int m_time;//時間用
};