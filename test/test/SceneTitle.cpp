//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
#include"GameL\Audio.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneMain.h"
#include"GameHead.h"


//�R���X�g���N�^
CSceneTitle::CSceneTitle()
{

}

//�f�X�g���N�^
CSceneTitle::~CSceneTitle()
{

}

//�Q�[�����C��������
void CSceneTitle::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"SweetParadise");
	Font::SetStrTex(L"GameStart");

	/*
	//���y���̓ǂݍ���
	Audio::LoadAudio(0, L"�^�C�g��(��3).wav", SOUND_TYPE::BACK_MUSIC);

	//�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(1.5f);//�}�X�^�[�{�����[����1.0�ɂ���
	Audio::Start(0);//���y�X�^�[�g*/

	//�^�C�g���I�u�W�F�N�g�쐬
	CObjTitle* obj = new CObjTitle();//�^�C�g���I�u�W�F�N�g
	Objs::InsertObj(obj, OBJ_TITLE, 10);//��l���I�u�W�F�N�g
}

void CSceneTitle::Scene()
{

}