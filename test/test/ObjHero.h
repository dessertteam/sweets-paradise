#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 主人公(蟻)
class CObjHero : public CObj
{
public:
	CObjHero() {}
	~CObjHero() {}

	void Init();	//イニシャライズ
	void Action();	//アクション
	void Draw();	//ドロー
private:
	float m_x;		//主人公(蟻)のX方向移動
	float m_y;		//主人公(蟻)のY方向移動
	float m_speed;	//主人公(蟻)の速さ
};