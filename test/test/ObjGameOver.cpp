#include "GameL\DrawFont.h"
#include"GameL\WinInputs.h"
#include"GameL\SceneManager.h"

#include"GameHead.h"
#include"ObjGameOver.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameOver::Init()
{

}

//�A�N�V����
void CObjGameOver::Action()
{
	//�G���^�[�L�[�������ăV�[��:�Q�[��Titlle�Ɉڍs����
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}
}
//�h���[
void CObjGameOver::Draw()
{

}