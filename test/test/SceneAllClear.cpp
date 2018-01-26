//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"
#include "GameL\Audio.h"

//�R���X�g���N�^
CSceneAllClear::CSceneAllClear()
{

}

//�f�X�g���N�^
CSceneAllClear::~CSceneAllClear()
{

}

//���������\�b�h
void CSceneAllClear::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"���S�N���A.wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.4 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	Font::SetStrTex(L"GameClear");

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512*512�s�N�Z��)
	Draw::LoadImage(L"char.png", 3, TEX_SIZE_512);

	//�N���A�I�u�W�F�N�g�쐬
	CObjClear* obj = new CObjClear();		//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 10);	//�N���A�I�u�W�F�N�g�o�^

}

//���s�����\�b�h
void CSceneAllClear::Scene()
{


}