#include"math.h"
//---UnitVec�֐�
//����1 float* vx :�x�N�g����X�����̃|�C���^
//����2 float* vy :�x�N�g����Y�����̃|�C���^
//�߂�l�@bool    :true=�v�Z���� false=�v�Z���s

bool UnitVec(float* vx, float* vy)
{
	//�x�N�g���̒��������߂�(�O�����̒藝)
	float r = 0.0f;
	r = (*vx)*(*vx) + (*vy)*(*vy);
	r = sqrt(r);

	//������0���ǂ������ׂ�
	if (r == 0.0f)
	{
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 1.0f / r*(*vx);
		(*vy) = 1.0f / r*(*vy);
	}


	return true;
}

//---CheckWindow�֐�
//����1 float pos_x   :�̈�O���ǂ������ׂ�x�ʒu
//����2 float pos_y   :�̈�O���ǂ������ׂ�Y�ʒu
//����3 float window_x :�̈��top�ʒu
//����4 float window_y :�̈��left�ʒu
//����5 float window_w :�̈��right�ʒu
//����6 float window_h :�̈��bottom�ʒu
//�߂�l�@bool     :true=�̈���@flase=�̈�O
//���e
//�̈�����ǂ������ׂ�ʒupos_(x,y)��window_(xywh)�̓����O���𒲂ׂ�
bool CheckWindow(float pos_x, float pos_y,
	float window_x, float window_y, float window_w, float window_h)
{
	if (pos_x < window_x)
	{
		return false;//�̈�O
	}
	if (pos_x > window_w)
	{
		return false;//�̈�O
	}
	if (pos_y < window_y)
	{
		return false;//�̈�O
	}
	if (pos_y > window_h)
	{
		return false;//�̈�O
	}
	return true;//�̈��
}
//---GetAtan2Angle�֐�
//����1 float w   :��
//����2 float h   :����
//�߂�l�@float   :�p�x(0���`360��)
//���e
//�����ƕ����璼�p�O�p�`������Ɖ��肵���̊p�x�����߂�B
float GetAtan2Angle(float w, float h)
{
	//atan2�Ŋp�x�����߂�
	float r = atan2(h, w)*180.0f / 3.14f;

	//-180���`-0����180���`360���ɕϊ�
	if (r < 0)
	{
		r = 360 - abs(r);
	}

	return r;
}

//��l���̈ʒu�𐔒l������֐�
//����1 int**  mapData  :���ׂ����}�b�v�f�[�^������
//����2 int PosX		:���ׂ����L�����N�^�[��X�ʒu������
//����3 int PosY		:���ׂ����L�����N�^�[��Y�ʒu������
//����4 int n			:�v�f�ԍ�
//�}�b�v�̋󔒂̕��������ׂĐ��l�����A�ǐՃL�����Ȃǂ̗D��x�����߂邽�߂̊֐�
//���E�㉺�������������Ă���B

void search(int** mapData, int PosX, int PosY,int n)
{
	n += 1;

	//��l���̉���0�܂��͗v�f�ԍ����傫���l�̂Ƃ��ɁA�v�f�ԍ�������
	if (mapData[PosY - 1][PosX] == 0 || mapData[PosY - 1][PosX] >= n)
	{
		mapData[PosY - 1][PosX] = n;
		//����ɉ��̕����ɂ��v�f�ԍ�������
		search(mapData, PosX, PosY-1, n);
	}

	//��l���̏オ0�܂��͗v�f�ԍ����傫���l�̂Ƃ��ɁA�v�f�ԍ�������
	if (mapData[PosY + 1][PosX] == 0 || mapData[PosY + 1][PosX] >= n)
	{
		mapData[PosY + 1][PosX] = n;
		//����ɏ�̕����ɂ��v�f�ԍ�������
		search(mapData, PosX, PosY + 1, n);
	}

	//��l���̍���0�܂��͗v�f�ԍ����傫���l�̂Ƃ��ɁA�v�f�ԍ�������
	if (mapData[PosY][PosX - 1] == 0 || mapData[PosY][PosX - 1] >= n)
	{
		mapData[PosY][PosX - 1] = n;
		//����ɍ��̕����ɂ��v�f�ԍ�������
		search(mapData, PosX - 1, PosY, n);
	}

	//��l���̉E��0�܂��͗v�f�ԍ����傫���l�̂Ƃ��ɁA�v�f�ԍ�������
	if (mapData[PosY][PosX + 1] == 0 || mapData[PosY][PosX + 1] >= n)
	{
		mapData[PosY][PosX + 1] = n;
		//����ɉE�̕����ɂ��v�f�ԍ�������
		search(mapData, PosX + 1, PosY, n);
	}
	return ;
}
//�}�b�v�f�[�^����������������ʒu�ɂP�O��o�^����֐�
//����1 int**  mapData  :���ׂ����}�b�v�f�[�^������
//����2 int PosX		:���ׂ����L�����N�^�[��X�ʒu������
//����3 int PosY		:���ׂ����L�����N�^�[��Y�ʒu������
//�}�b�v�f�[�^�����ׂď��������A������ʒu��10��o�^���ėv�f�ԍ���t���n�߂�
void moveDataSet(int** mapData, int PosX, int PosY)
{
	//�}�b�v�f�[�^�̏�����
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			//1�i�ǁj����Ȃ��Ƃ��ɂO�i�󔒁j�ɂ���
			if (mapData[i][j] != 1)
			{
				mapData[i][j] = 0;
			}
		}
	}
	//������ʒu��10�ɐݒ�
	mapData[PosY][PosX] = 10;
	//�v�f�ԍ�������
	search(mapData, PosX, PosY, 10);

}

//�v���C���[�̈ʒu�ɍŒZ�����ňړ�����֐�
//����1 int**  mapData  :���ׂ����}�b�v�f�[�^������
//����2 int x			:������X�ʒu������
//����3 int y			:������Y�ʒu������
//����4 int v			:�v�f�ԍ�
//����5 int TargetX		:�T���������^�[�Q�b�g��X�ʒu������
//����6 int TargetY		:�T���������^�[�Q�b�g��Y�ʒu������
void fastMove(int** mapData,int* x, int* y, int* v, int TargetX, int TargetY)
{
	//�^�[�Q�b�g�̈ʒu��T������
	moveDataSet(mapData, TargetX, TargetY);

  //�������猩�ă^�[�Q�b�g�ɂ��߂�������T������
	//��
	if (mapData[*y - 1][*x] != 1 && mapData[*y - 1][*x] < mapData[*y][*x])
	{
		*y -= 1;
		*v = 3;
	}
	//��
	if (mapData[*y + 1][*x] != 1 && mapData[*y + 1][*x] < mapData[*y][*x])
	{
		*y +=1;
		*v =1;
	}
	//��
	if (mapData[*y][*x - 1] != 1 && mapData[*y][*x - 1] < mapData[*y][*x])
	{
		*x -= 1;
		*v = 0;
	}
	//�E
	if (mapData[*y][*x + 1] != 1 && mapData[*y][*x + 1] < mapData[*y][*x])
	{
		*x += 1;
		*v = 0;
	}
}

