#pragma once


//プロトタイプ宣言
bool UnitVec(float* vx, float* vy);

bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h);//領域内かどうかをチェックする関数

float GetAtan2Angle(float w, float h);

void Searching(int mapData[19][25], int PosX, int PosY, int n);
void moveDataSet(int mapData[19][25], int PosX, int PosY);
void fastMove(int mapData[19][25], int* x, int* y, int* v, int TargetX, int TargetY);