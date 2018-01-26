#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクト : オールクリア
class CObjAllClear :public CObj
{
public:
	CObjAllClear() {};
	~CObjAllClear() {};
	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	bool m_key_flag;//キーフラグ
};