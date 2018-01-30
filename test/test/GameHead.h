#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
					//ゲームで使うオブジェクトの名前
					//OBJ_○○と表記
					OBJ_HERO,
					OBJ_FENEMY,
					OBJ_BLOCK,
					OBJ_TITLE,
					OBJ_HOLE,
					OBJ_GAME_OVER,
					OBJ_YUKIDARUMA,
					OBJ_KURI,
					OBJ_ONIKURI,
					OBJ_SYMMETRY,
					OBJ_TIME,
					OBJ_CLEAR,
					OBJ_ALLCLEAR,
					OBJ_SWEETS,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
				 //以下　同じ属性同士では当たり判定は実行されない
				 //属性は追加可能だが、デバック時の色は初期設定分しか無い
				 ELEMENT_PLAYER,
				 ELEMENT_ENEMY,
				 ELEMENT_ITEM,
				 ELEMENT_MAGIC,
				 ELEMENT_FIELD,
				 ELEMENT_RED,
				 ELEMENT_GREEN,
				 ELEMENT_BLUE,
				 ELEMENT_BLACK,
				 ELEMENT_WHITE,
				 ELEMENT_SWEETS,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;	//サンプルセーブデータ
	int m_cal;      //GameMainで得たカロリー
	int m_ranking[10]; //ランキング情報

};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjHero.h"
#include "ObjFEnemy.h"
#include "ObjBlock.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjYukidaruma.h"
#include "ObjSymmetry.h"
#include "ObjTime.h"
#include "ObjClear.h"
#include "ObjKuri.h"
#include "ObjOnikuri.h"
#include "Objhole.h"
#include "ObjSweets.h"
#include "ObjAllClear.h"
//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneClear.h"
#include "SceneAllClear.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------