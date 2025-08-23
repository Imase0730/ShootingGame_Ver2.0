//--------------------------------------------------------------------------------------
// File: GamePlayScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/Screen.h"
#include "Game/Common/Scene.h"
#include "Game/Common/TaskManager.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"

// �N���X�̑O���錾
class Game;

// �Q�[���v���C�V�[��
class GamePlayScene : public Scene
{
	// �񋓌^�̐錾 -------------------------------------------------
public:

	// �Q�[���̏��
	enum class GameState
	{
		GamePlay,	// �ʏ�
		GameOver,	// �Q�[���I�[�o�[
	};

	// �N���X�萔�̐錾 -------------------------------------------------
public:

	// �Q�[���I�[�o�[�̕�����
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// �v���C���[�����ʒu
	static constexpr int PLAYER_START_POSITION_X = Screen::WIDTH / 2;
	static constexpr int PLAYER_START_POSITION_Y = 600;

	// �G�̍ő吔
	static constexpr int ENEMY_MAX = 10;

	// �v���C���[�̒e�̍ő吔
	static constexpr int PLAYER_BULLET_MAX = 3;

	// �G�̒e�̍ő吔
	static constexpr int ENEMY_BULLET_MAX = 3;

	// �f�[�^�����o�̐錾 -----------------------------------------------
private:

	// �Q�[���̏��
	GameState m_gameState;

	// �^�X�N�}�l�[�W���[
	Imase::TaskManager m_taskManager;

	// Game�ւ̃|�C���^
	Game* m_pGame;

	// �G�̃O���t�B�b�N�n���h��
	int m_ghTexture;

	// �v���C���[�ւ̃|�C���^
	Player* m_pPlayer;

	// �G�̃}�l�[�W���[�ւ̃|�C���^
	EnemyManager* m_pEnemyManager;

	// �v���C���[�̒e�̃}�l�[�W���[�ւ̃|�C���^
	BulletManager* m_pPlayerBulletManager;

	// �G�̒e�̃}�l�[�W���[�ւ̃|�C���^
	BulletManager* m_pEnemyBulletManager;

	// �����o�֐��̐錾 -------------------------------------------------
public:

	// �R���X�g���N�^
	GamePlayScene(Game* pGame);

	// �f�X�g���N�^
	~GamePlayScene();

	// ����������
	void Initialize() override;

	// �X�V����
	void Update(float elapsedTime) override;

	// �`�揈��
	void Render() override;

	// �I������
	void Finalize() override;

private:

	// �v���C���[�̈ړ�
	void MovePlayer();

	// �G�ƒe�Ƃ̏Փ˔���
	void CheckEnemiesColliedWithBullets(const std::vector<Enemy*>& enemies, const std::vector<Bullet*>& bullets);

	// �v���C���[�ƒe�Ƃ̏Փ˔���
	void CheckPlayerColliedWithBullets(Player* player, const std::vector<Bullet*>& bullets);

};
