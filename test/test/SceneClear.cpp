//STL�f�o�b�N�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneClear.h"
#include "GameHead.h"
#include "GameL\Audio.h"

//�R���X�g���N�^
CSceneClear::CSceneClear()
{

}

//�f�X�g���N�^
CSceneClear::~CSceneClear()
{

}

//���������\�b�h
void CSceneClear::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�Q�[���N���A(��2).wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((1.0 - v));

	//���y�X�^�[�g
	Audio::Start(0);


	//�N���A�I�u�W�F�N�g�쐬
	CObjClear* obj = new CObjClear();		//�N���A�I�u�W�F�N�g�쐬
	Objs::InsertObj(obj, OBJ_CLEAR, 10);	//�N���A�I�u�W�F�N�g�o�^
}

//���s�����\�b�h
void CSceneClear::Scene()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GameClear", 300, 250, 50, c);
	Font::StrDraw(L"Push   EnterKey", 300, 400, 30, c);
}