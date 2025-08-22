//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"

// �R���X�g���N�^
GamePlayScene::GamePlayScene(Game* pGame)
	: Scene(pGame->GetSceneManager())
	, m_gameState{ GameState::GamePlay }
	, m_taskManager{}
	, m_pGame(pGame)
	, m_ghTexture{ -1 }
	, m_pPlayer{ nullptr }
	, m_pEnemyManager{ nullptr }
	, m_pPlayerBulletManager{ nullptr }
	, m_pEnemyBulletManager{ nullptr }
{

}

// �f�X�g���N�^
GamePlayScene::~GamePlayScene()
{
	// �e�̃}�l�[�W���[�̉��
	if (m_pPlayerBulletManager) delete m_pPlayerBulletManager;
	if (m_pEnemyBulletManager) delete m_pEnemyBulletManager;
}

// ����������
void GamePlayScene::Initialize()
{
	// �Q�[���v���C��
	m_gameState = GameState::GamePlay;

	// �G�̓ǂݍ���
	m_ghTexture = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// �v���C���[�^�X�N�̓o�^
	m_pPlayer = m_taskManager.AddTask<Player>(m_ghTexture);

	// �v���C���[�̈ʒu�𒆉��ɐݒ�
	m_pPlayer->SetPosition(Vector2D{ PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y });

	// �v���C���[�̒e�̃}�l�[�W���[�̍쐬
	m_pPlayerBulletManager = new BulletManager(&m_taskManager, PLAYER_BULLET_MAX, m_ghTexture);

	// �G�̒e�̃}�l�[�W���[�̍쐬
	m_pEnemyBulletManager = new BulletManager(&m_taskManager, ENEMY_BULLET_MAX, m_ghTexture);

	// �G�̃}�l�[�W���[�̃^�X�N�o�^
	m_pEnemyManager = m_taskManager.AddTask<EnemyManager>(&m_taskManager, ENEMY_MAX, m_ghTexture, m_pEnemyBulletManager);
}

// �X�V����
void GamePlayScene::Update(float elapsedTime)
{
	int keyTrigger = m_pGame->GetKeyTrigger();

	switch (m_gameState)
	{
	case GameState::GamePlay:

		// �v���C���[���A�N�e�B�u�Ȃ�
		if (m_pPlayer->IsActive()) MovePlayer();

		// �^�X�N�}�l�[�W���[�̍X�V����
		m_taskManager.Update(elapsedTime);

		// �G�ƒe�̏Փ˔���
		CheckEnemiesColliedWithBullets(m_pEnemyManager->GetEnemies(), m_pPlayerBulletManager->GetBullets());

		// �v���C���[�ƒe�̏Փ˔���
		CheckPlayerColliedWithBullets(m_pPlayer, m_pEnemyBulletManager->GetBullets());

		break;

	case GameState::GameOver:

		// �X�y�[�X�L�[�Ń^�C�g����
		if (keyTrigger & PAD_INPUT_10)
		{
			ChangeScene("Title");
		}

		// �^�X�N�}�l�[�W���[�̍X�V����
		m_taskManager.Update(elapsedTime);

		break;

	default:
		break;

	}
}

// �`�揈��
void GamePlayScene::Render()
{
	// �^�X�N�}�l�[�W���[�̕`�揈��
	m_taskManager.Render();

	// �Q�[���I�[�o�[�Ȃ�
	if (m_gameState == GameState::GameOver)
	{
		// �Q�[���^�C�g���̕\��
		DrawFormatString(Screen::WIDTH / 2 - GetDrawStringWidth(GAMEOVER, static_cast<int>(wcslen(GAMEOVER))) / 2
			, Screen::HEIGHT / 2 - Game::FONT_SIZE / 2
			, GetColor(255, 255, 255), GAMEOVER);
	}
}

// �I������
void GamePlayScene::Finalize()
{
	// �ǂݍ��񂾊G�̉��
	if (m_ghTexture != -1)
	{
		DeleteGraph(m_ghTexture);
		m_ghTexture = - 1;
	}
}

// �v���C���[�̈ړ�
void GamePlayScene::MovePlayer()
{
	int keyCondition = m_pGame->GetKeyCondition();
	int keyTrigger = m_pGame->GetKeyTrigger();

	// �v���C���[���~����
	m_pPlayer->MoveStop();

	if (keyCondition & PAD_INPUT_LEFT)
	{
		// ���Ɉړ�
		m_pPlayer->MoveLeft();
	}

	if (keyCondition & PAD_INPUT_RIGHT)
	{
		// �E�Ɉړ�
		m_pPlayer->MoveRight();
	}

	if (keyTrigger & PAD_INPUT_10)
	{
		// �e�𔭎�
		m_pPlayerBulletManager->ShootBullet(m_pPlayer->GetPosition(), Vector2D{ 0.0f, -10.0f }, Bullet::Type::Player);
	}
}

// �G�ƒe�̏Փ˔���
void GamePlayScene::CheckEnemiesColliedWithBullets(const std::vector<Enemy*>& enemies, const std::vector<Bullet*>& bullets)
{
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->IsActive())
		{
			for (int j = 0; j < bullets.size(); j++)
			{
				if (bullets[j]->IsActive())
				{
					if (IsCircleColliding(enemies[i]->GetBoundingCircle(), bullets[j]->GetBoundingCircle()))
					{
						enemies[i]->SetActive(false);
						bullets[j]->SetActive(false);
						m_taskManager.AddTask<Explosion>(enemies[i]->GetPosition(), m_ghTexture);
					}
				}
			}
		}
	}
}

// �v���C���[�ƒe�Ƃ̏Փ˔���
void GamePlayScene::CheckPlayerColliedWithBullets(Player* player, const std::vector<Bullet*>& bullets)
{
	if (player->IsActive())
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (bullets[j]->IsActive())
			{
				if (IsCircleColliding(player->GetBoundingCircle(), bullets[j]->GetBoundingCircle()))
				{
					player->SetActive(false);
					bullets[j]->SetActive(false);
					m_taskManager.AddTask<Explosion>(player->GetPosition(), m_ghTexture);

					// �Q�[���I�[�o�[				
					m_gameState = GameState::GameOver;
				}
			}
		}
	}
}

