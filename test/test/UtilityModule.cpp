#include"math.h"
//---UnitVec関数
//引数1 float* vx :ベクトルのX成分のポインタ
//引数2 float* vy :ベクトルのY成分のポインタ
//戻り値　bool    :true=計算成功 false=計算失敗

bool UnitVec(float* vx, float* vy)
{
	//ベクトルの長さを求める(三平方の定理)
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//長さが0かどうか調べる
	if (r == 0.0f)
	{
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}


	return true;
}

//---CheckWindow関数
//引数1 float pos_x   :領域外かどうか調べるx位置
//引数2 float pos_y   :領域外かどうか調べるY位置
//引数3 float window_x :領域のtop位置
//引数4 float window_y :領域のleft位置
//引数5 float window_w :領域のright位置
//引数6 float window_h :領域のbottom位置
//戻り値　bool     :true=領域内　flase=領域外
//内容
//領域内かどうか調べる位置pos_(x,y)がwindow_(xywh)の内か外かを調べる
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	if (pos_x < window_x)
	{
		return false;//領域外
	}
	if (pos_x > window_w)
	{
		return false;//領域外
	}
	if (pos_y < window_y)
	{
		return false;//領域外
	}
	if (pos_y > window_h)
	{
		return false;//領域外
	}
	return true;//領域内
}
//---GetAtan2Angle関数
//引数1 float w   :幅
//引数2 float h   :高さ
//戻り値　float   :角度(0°～360°)
//内容
//高さと幅から直角三角形があると仮定しその角度を求める。
float GetAtan2Angle(float w, float h)
{
	//atan2で角度を求める
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180°～-0°を180°～360°に変換
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;
}

//主人公の位置を数値化する関数
//引数1 int**  mapData  :調べたいマップデータを入れる
//引数2 int PosX		:調べたいキャラクターのX位置を入れる
//引数3 int PosY		:調べたいキャラクターのY位置を入れる
//引数4 int n			:要素番号
//マップの空白の部分をすべて数値化し、追跡キャラなどの優先度を決めるための関数
//左右上下同じ処理をしている。

void search(int** mapData, int PosX, int PosY,int n)
{
	n += 1;

	//主人公の下が0または要素番号より大きい値のときに、要素番号をつける
	if (mapData[PosY - 1][PosX] == 0 || mapData[PosY - 1][PosX] >= n)
	{
		mapData[PosY - 1][PosX] = n;
		//さらに下の部分にも要素番号をつける
		search(mapData, PosX, PosY-1, n);
	}

	//主人公の上が0または要素番号より大きい値のときに、要素番号をつける
	if (mapData[PosY + 1][PosX] == 0 || mapData[PosY + 1][PosX] >= n)
	{
		mapData[PosY + 1][PosX] = n;
		//さらに上の部分にも要素番号をつける
		search(mapData, PosX, PosY + 1, n);
	}

	//主人公の左が0または要素番号より大きい値のときに、要素番号をつける
	if (mapData[PosY][PosX - 1] == 0 || mapData[PosY][PosX - 1] >= n)
	{
		mapData[PosY][PosX - 1] = n;
		//さらに左の部分にも要素番号をつける
		search(mapData, PosX - 1, PosY, n);
	}

	//主人公の右が0または要素番号より大きい値のときに、要素番号をつける
	if (mapData[PosY][PosX + 1] == 0 || mapData[PosY][PosX + 1] >= n)
	{
		mapData[PosY][PosX + 1] = n;
		//さらに右の部分にも要素番号をつける
		search(mapData, PosX + 1, PosY, n);
	}
	return ;
}
//マップデータを初期化し今いる位置に１０を登録する関数
//引数1 int**  mapData  :調べたいマップデータを入れる
//引数2 int PosX		:調べたいキャラクターのX位置を入れる
//引数3 int PosY		:調べたいキャラクターのY位置を入れる
//マップデータをすべて初期化し、今いる位置に10を登録して要素番号を付け始める
void moveDataSet(int** mapData, int PosX, int PosY)
{
	//マップデータの初期化
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			//1（壁）じゃないときに０（空白）にする
			if (mapData[i][j] != 1)
			{
				mapData[i][j] = 0;
			}
		}
	}
	//今いる位置を10に設定
	mapData[PosY][PosX] = 10;
	//要素番号をつける
	search(mapData, PosX, PosY, 10);

}

//プレイヤーの位置に最短距離で移動する関数
//引数1 int**  mapData  :調べたいマップデータを入れる
//引数2 int x			:自分のX位置を入れる
//引数3 int y			:自分のY位置を入れる
//引数4 int v			:要素番号
//引数5 int TargetX		:探索したいターゲットのX位置を入れる
//引数6 int TargetY		:探索したいターゲットのY位置を入れる
void fastMove(int** mapData,int* x, int* y, int* v, int TargetX, int TargetY)
{
	//ターゲットの位置を探索する
	moveDataSet(mapData, TargetX, TargetY);

  //自分から見てターゲットにより近い方向を探す処理
	//下
	if (mapData[*y - 1][*x] != 1 && mapData[*y - 1][*x] < mapData[*y][*x])
	{
		*y -= 1;
		*v = 3;
	}
	//上
	if (mapData[*y + 1][*x] != 1 && mapData[*y + 1][*x] < mapData[*y][*x])
	{
		*y +=1;
		*v =1;
	}
	//左
	if (mapData[*y][*x - 1] != 1 && mapData[*y][*x - 1] < mapData[*y][*x])
	{
		*x -= 1;
		*v = 0;
	}
	//右
	if (mapData[*y][*x + 1] != 1 && mapData[*y][*x + 1] < mapData[*y][*x])
	{
		*x += 1;
		*v = 0;
	}
}

