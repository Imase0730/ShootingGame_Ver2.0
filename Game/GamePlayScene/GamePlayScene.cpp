//--------------------------------------------------------------------------------------
// File: GamePlayScene.cpp
//
//--------------------------------------------------------------------------------------
#include "GamePlayScene.h"
#include "Game/Game.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Explosion.h"

// コンストラクタ
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

// デストラクタ
GamePlayScene::~GamePlayScene()
{
	// 弾のマネージャーの解放
	if (m_pPlayerBulletManager) delete m_pPlayerBulletManager;
	if (m_pEnemyBulletManager) delete m_pEnemyBulletManager;
}

// 初期化処理
void GamePlayScene::Initialize()
{
	// ゲームプレイへ
	m_gameState = GameState::GamePlay;

	// 絵の読み込み
	m_ghTexture = LoadGraph(L"Resources/Textures/ShootingGame.png");

	// プレイヤータスクの登録
	m_pPlayer = m_taskManager.AddTask<Player>(m_ghTexture);

	// プレイヤーの位置を中央に設定
	m_pPlayer->SetPosition(Vector2D{ PLAYER_START_POSITION_X, PLAYER_START_POSITION_Y });

	// プレイヤーの弾のマネージャーの作成
	m_pPlayerBulletManager = new BulletManager(&m_taskManager, PLAYER_BULLET_MAX, m_ghTexture);

	// 敵の弾のマネージャーの作成
	m_pEnemyBulletManager = new BulletManager(&m_taskManager, ENEMY_BULLET_MAX, m_ghTexture);

	// 敵のマネージャーのタスク登録
	m_pEnemyManager = m_taskManager.AddTask<EnemyManager>(&m_taskManager, ENEMY_MAX, m_ghTexture, m_pEnemyBulletManager);
}

// 更新処理
void GamePlayScene::Update(float elapsedTime)
{
	int keyTrigger = m_pGame->GetKeyTrigger();

	switch (m_gameState)
	{
	case GameState::GamePlay:

		// プレイヤーがアクティブなら
		if (m_pPlayer->IsActive()) MovePlayer();

		// タスクマネージャーの更新処理
		m_taskManager.Update(elapsedTime);

		// 敵と弾の衝突判定
		CheckEnemiesColliedWithBullets(m_pEnemyManager->GetEnemies(), m_pPlayerBulletManager->GetBullets());

		// プレイヤーと弾の衝突判定
		CheckPlayerColliedWithBullets(m_pPlayer, m_pEnemyBulletManager->GetBullets());

		break;

	case GameState::GameOver:

		// スペースキーでタイトルへ
		if (keyTrigger & PAD_INPUT_10)
		{
			ChangeScene("Title");
		}

		// タスクマネージャーの更新処理
		m_taskManager.Update(elapsedTime);

		break;

	default:
		break;

	}
}

// 描画処理
void GamePlayScene::Render()
{
	// タスクマネージャーの描画処理
	m_taskManager.Render();

	// ゲームオーバーなら
	if (m_gameState == GameState::GameOver)
	{
		// ゲームタイトルの表示
		DrawFormatString(Screen::WIDTH / 2 - GetDrawStringWidth(GAMEOVER, static_cast<int>(wcslen(GAMEOVER))) / 2
			, Screen::HEIGHT / 2 - Game::FONT_SIZE / 2
			, GetColor(255, 255, 255), GAMEOVER);
	}
}

// 終了処理
void GamePlayScene::Finalize()
{
	// 読み込んだ絵の解放
	if (m_ghTexture != -1)
	{
		DeleteGraph(m_ghTexture);
		m_ghTexture = - 1;
	}
}

// プレイヤーの移動
void GamePlayScene::MovePlayer()
{
	int keyCondition = m_pGame->GetKeyCondition();
	int keyTrigger = m_pGame->GetKeyTrigger();

	// プレイヤーを停止する
	m_pPlayer->MoveStop();

	if (keyCondition & PAD_INPUT_LEFT)
	{
		// 左に移動
		m_pPlayer->MoveLeft();
	}

	if (keyCondition & PAD_INPUT_RIGHT)
	{
		// 右に移動
		m_pPlayer->MoveRight();
	}

	if (keyTrigger & PAD_INPUT_10)
	{
		// 弾を発射
		m_pPlayerBulletManager->ShootBullet(m_pPlayer->GetPosition(), Vector2D{ 0.0f, -10.0f }, Bullet::Type::Player);
	}
}

// 敵と弾の衝突判定
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

// プレイヤーと弾との衝突判定
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

					// ゲームオーバー				
					m_gameState = GameState::GameOver;
				}
			}
		}
	}
}

