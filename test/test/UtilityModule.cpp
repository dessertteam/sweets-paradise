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