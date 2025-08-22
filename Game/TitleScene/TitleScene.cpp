//--------------------------------------------------------------------------------------
// File: TitleScene.cpp
//
//--------------------------------------------------------------------------------------
#include "TitleScene.h"
#include "Game/Game.h"

// �R���X�g���N�^
TitleScene::TitleScene(Game* pGame)
	: Scene(pGame->GetSceneManager())
	, m_pGame(pGame)
{

}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
}

// ����������
void TitleScene::Initialize()
{
}

// �X�V����
void TitleScene::Update(float elapsedTime)
{
	int keyTrigger = m_pGame->GetKeyTrigger();

	// �X�y�[�X�L�[�ŃQ�[���X�^�[�g
	if (keyTrigger & PAD_INPUT_10)
	{
		ChangeScene("GamePlay");
	}
}

// �`�揈��
void TitleScene::Render()
{
	// �Q�[���^�C�g���̕\��
	DrawFormatString(Screen::WIDTH / 2 - GetDrawStringWidth(TITLE, static_cast<int>(wcslen(TITLE))) / 2
		, Screen::HEIGHT / 2 - Game::FONT_SIZE / 2
		, GetColor(255, 255, 255), TITLE);
}

// �I������
void TitleScene::Finalize()
{
}

