//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL (0)
#define _HAS_ITERATOR_DEBUGGING (0)

//GameL�Ŏg�p����w�b�_�[
#include"GameL\SceneObjManager.h"
#include"GameL\DrawFont.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include"SceneGameOver.h"
#include"GameHead.h"
#include "GameL\Audio.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}

//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}

//�Q�[�����C��������
void CSceneGameOver::InitScene()
{
	//���y�ǂݍ���
	Audio::LoadAudio(0, L"�Q�[���I�[�o�[(��1).wav", BACK_MUSIC);

	//�{�����[����1.0�ɖ߂�
	float v = Audio::VolumeMaster(0);
	v = Audio::VolumeMaster((0.5 - v));

	//���y�X�^�[�g
	Audio::Start(0);

	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GAME OVER");

	//�O���O���t�B�b�N�t�@�C����ǂݍ���3�Ԃɓo�^(512*512�s�N�Z��)
	Draw::LoadImage(L"char.png", 3, TEX_SIZE_512);

	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameOver* obj = new CObjGameOver();
	Objs::InsertObj(obj, OBJ_GAME_OVER, 10);

}

void CSceneGameOver::Scene()
{

}