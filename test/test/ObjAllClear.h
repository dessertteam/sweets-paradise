#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//定数
//マウスクリックのメイン遷移
#define MOU_MAIN_HIT_X (230)
#define MOU_MAIN_HIT_W (450)
#define MOU_MAIN_HIT_Y (400)
#define MOU_MAIN_HIT_H (430)

//描画関係の定数
#define TITLE_POS_X		(200)
#define TITLE_POS_Y		(250)
#define TITLE_FONT_SIZE (40)

#define RANKING_POS_X	  (310)
#define RANKING_POS_Y	  (250)
#define RANKING_FONT_SIZE (32)
#define RANKING_SCORE_MAX (9)
#define STR_MAX			  (256)
#define SCORE_INIT		  (1)
#define SCORE_POS_X		  (260)
#define SCORE_POS_Y		  (304)
#define SCORE_POINT_MAX	  (100)
#define SCORE_INTERVAL	  (24)
#define SCORE_FONT_SIZE	  (24)

#define CLICK_START_POS_X	  (230)
#define CLICK_START_POS_Y	  (400)
#define CLICK_START_FONT_SIZE (30)

#define CLICK_RESET_POS_X	  (260)
#define CLICK_RESET_POS_Y	  (530)
#define CLICK_RESET_FONT_SIZE (32)

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
	float m_mou_x;  //マウスの位置X
	float m_mou_y;  //マウスの位置Y
	bool  m_mou_r;  //マウスの右ボタン
	bool  m_mou_l;  //マウスの左ボタン

	bool m_key_flag;//キーフラグ

					//ランキングソートメソッド
	void RankingSort(int rank[10]);
};