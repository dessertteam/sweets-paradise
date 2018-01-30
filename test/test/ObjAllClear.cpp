//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"

#include "GameHead.h"
#include "ObjClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjAllClear::Init()
{
	m_mou_x = 0.0f;
	m_mou_y = 0.0f;
	m_mou_r = false;
	m_mou_l = false;

	//ゲーム実行して一回のみ
	static bool init_point = false;
	if (init_point == false)
	{
		for (int i = 0; i < 10; i++)
		{
			((UserData*)Save::GetData())->m_ranking[i] = 0;
		}

		//ロード
		//Save::Open();//同フォルダ「UserData」からデータ取得。

		//点数を0にする
		init_point = true;
	}

	//得点情報をランキング最下位(描画圏外)に登録
	((UserData*)Save::GetData())->m_ranking[9] = ((UserData*)Save::GetData())->m_cal;

	//得点が高い順に並び替える
	RankingSort(((UserData*)Save::GetData())->m_ranking);

	//ゲーム実行して一回のみ以外、ランキングを自動セーブする
	if (init_point == true)
	{
		//Save::Seve();//UserDataの情報を同フォルダ「UserData」を作成
	}

}

//アクション
void CObjAllClear::Action()
{
	//マウスの位置を取得
	m_mou_x = (float)Input::GetPosX();
	m_mou_y = (float)Input::GetPosY();

	//マウスのボタンの状態
	m_mou_r = Input::GetMouButtonR();
	m_mou_l = Input::GetMouButtonL();

	//ランキングリセットの部分との当たり判定
	if (m_mou_x > CLICK_RESET_POS_X&&m_mou_x<CLICK_RESET_POS_X + 100 &&
		m_mou_y>CLICK_RESET_POS_Y&&m_mou_y < CLICK_RESET_POS_Y + 32)
	{
		if (m_mou_r == true || m_mou_l == true)
		{
			//ランキング初期化
			for (int i = 0; i < 10; i++)
			{
				((UserData*)Save::GetData())->m_ranking[i] = 0;
			}
		}
		m_mou_r = false;
		m_mou_l = false;
	}

	//エンターキーを押してシーン:タイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}
}

//ドロー
void CObjAllClear::Draw()
{
	//描画カラー情報　R=RED G=Green B=Blue A=Alpha(透過情報)
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

			   //ランキング
	Font::StrDraw(L"ランキング", RANKING_POS_X, RANKING_POS_Y, RANKING_FONT_SIZE, c);
	for (int i = 0; i < RANKING_SCORE_MAX; i++)
	{
		wchar_t str[STR_MAX];
		swprintf_s(str, L"%2d位%12d点", i + SCORE_INIT, ((UserData*)Save::GetData())->m_ranking[i]);
		Font::StrDraw(str, SCORE_POS_X, SCORE_POS_Y + SCORE_INTERVAL*i, SCORE_FONT_SIZE, c);
	}

	//ランキングリセット場所
	Font::StrDraw(L"◆ClickReset", CLICK_RESET_POS_X, CLICK_RESET_POS_Y, CLICK_RESET_FONT_SIZE, c);

	//切り取り位置の設定
	src.m_top = 113.0f;
	src.m_left = 5.0f;
	src.m_right = 508.0f;
	src.m_bottom = 146.0f;

	//表示位置の設定
	dst.m_top = 140.0f;
	dst.m_left = 250.0f;
	dst.m_right = 850.0f;
	dst.m_bottom = 200.0f;

	Draw::Draw(3, &src, &dst, c, 0.0f);


}

//ランキングソートメソッド
//引数1 int[16] :ランキング用配列
//高順でバブルソートを行う
void CObjAllClear::RankingSort(int rank[10])
{
	//値交換用変数
	int w;

	//バブルソート
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (rank[i] < rank[j])
			{
				//値の交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;

			}
		}
	}
}