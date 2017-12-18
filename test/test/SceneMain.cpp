//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//�g�p����w�b�_�[
#include "GameL\DrawTexture.h"
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "UtilityModule.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{
	
}

//�Q�[�����C���̏��������\�b�h
void CSceneMain::InitScene()
{
	//�O���O���t�B�b�N�t�@�C����ǂݍ���0�Ԃɓo�^(512*512�s�N�Z��)
	Draw::LoadImage(L"character.png", 0, TEX_SIZE_512);

	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();		//��l���I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_HERO, 10);	//�������l���I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	//block�I�u�W�F�N�g�쐬
	CObjBlock* objb = new CObjBlock();
	Objs::InsertObj(objb, OBJ_BLOCK, 9);

	//�Ⴞ��܃I�u�W�F�N�g�쐬
	CObjYukidaruma* obj_yukidaruma = new CObjYukidaruma();  //�Ⴞ��܃I�u�W�F�N�g�쐬
	Objs::InsertObj(obj_yukidaruma, OBJ_YUKIDARUMA, 10);     //������Ⴞ��܃I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

	 //Test�p �G�I�u�W�F�N�g�쐬
	CObjFEnemy* obje = new CObjFEnemy(600, 500);
	Objs::InsertObj(obje, OBJ_FENEMY, 10);

	//�G(�h�[�i�c)�I�u�W�F�N�g�쐬
	CObjSymmetry* objd = new CObjSymmetry(); //�G(�h�[�i�c)�I�u�W�F�N�g�쐬
	Objs::InsertObj(objd, OBJ_SYMMETRY, 10); //������G(�h�[�i�c)�I�u�W�F�N�g���I�u�W�F�N�g�}�l�[�W���[�ɓo�^

}

//�Q�[�����C���̎��s�����\�b�h
void CSceneMain::Scene()
{
	//�}�b�v�𐔒l�����鏈���ł��B
	//���܂������Ȃ������̂łƂ肠�����R�����g

	//CObjBlock map2;
	//CObjHero h1;
	//int x, y;
	//x = h1.GetX();
	//y = h1.GetY();
	//Searching(map2.m_map,x/32,y/32, 10);

}