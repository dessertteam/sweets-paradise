//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "ObjTime.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTime::Init()
{
	m_time = 3600;
	m_time2 = 0;
	m_time3 = 0;
	m_flag_time = false;
}

//�A�N�V����
void CObjTime::Action()
{
	m_time--;
	m_time2++;
	m_time3++;

	if (m_time2>1800)
	{
		m_time2 = 0;
		CObjYukidaruma* obj_yukidaruma = new CObjYukidaruma();  //�Ⴞ��܃I�u�W�F�N�g�쐬
		Objs::InsertObj(obj_yukidaruma, OBJ_YUKIDARUMA, 10);     //������Ⴞ��܃I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

		CObjSymmetry* objd = new CObjSymmetry(); //�G(�h�[�i�c)�I�u�W�F�N�g�쐬
		Objs::InsertObj(objd, OBJ_SYMMETRY, 10); //������G(�h�[�i�c)�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^
	}

	if (m_time3 > 900)
	{
		m_time3 = 0;

		CObjFEnemy* obje = new CObjFEnemy(600, 500);//���΂�
		Objs::InsertObj(obje, OBJ_FENEMY, 10);//���΂�
	}

	if (m_time < 0)
	{
		Scene::SetScene(new CSceneClear());
	}
}

//�h���[
void CObjTime::Draw()
{
	//m_time����b�����߂�
	int second;//�b

	second = (m_time / 60) % 60;//�b

	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"%d", second);//�b�̒l�𕶎���
	Font::StrDraw(str, 10, 10, 20, c);
}