//--------------------------------------------------------------------------------------
// File: TitleScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/Common/Scene.h"
#include "Game/Screen.h"

// �N���X�̑O���錾
class Game;

// �^�C�g���V�[��
class TitleScene : public Scene
{

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �^�C�g���̕�����
	static constexpr wchar_t TITLE[] = L"Shooting Game";

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// Game�ւ̃|�C���^
	Game* m_pGame;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	TitleScene(Game* pGame);

	// �f�X�g���N�^
	~TitleScene();

	// ����������
	void Initialize() override;

	// �X�V����
	void Update(float elapsedTime) override;

	// �`�揈��
	void Render() override;

	// �I������
	void Finalize() override;

};
