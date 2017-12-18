#pragma once
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト : 穴
class Hole
{
public:
	Hole();
	~Hole();

	void Init();
	void Action();
	void Draw();

	float m_ani_max_time;//アニメーションフレーム動作間隔最大値
	int m_ani_time;		//アニメーションフレーム動作間隔
	int m_ani_frame;	//描画フレーム

	float m_x;//位置x
	float m_y;//位置y

};

