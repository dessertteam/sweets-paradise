#pragma once
//使用するヘッダー
#include"GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト::ゲームオーバー
class CObjGameOver :public CObj
{
public:
	CObjGameOver() {};
	~CObjGameOver() {};
	void Init();//イニシャライズ
	void Action(); //アクション
	void Draw();//ドロー
private:
	bool m_key_flag;//キーフラグ
};