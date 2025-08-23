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

// クラスの前方宣言
class Game;

// ゲームプレイシーン
class GamePlayScene : public Scene
{
	// 列挙型の宣言 -------------------------------------------------
public:

	// ゲームの状態
	enum class GameState
	{
		GamePlay,	// 通常
		GameOver,	// ゲームオーバー
	};

	// クラス定数の宣言 -------------------------------------------------
public:

	// ゲームオーバーの文字列
	static constexpr wchar_t GAMEOVER[] = L"Game Over";

	// プレイヤー初期位置
	static constexpr int PLAYER_START_POSITION_X = Screen::WIDTH / 2;
	static constexpr int PLAYER_START_POSITION_Y = 600;

	// 敵の最大数
	static constexpr int ENEMY_MAX = 10;

	// プレイヤーの弾の最大数
	static constexpr int PLAYER_BULLET_MAX = 3;

	// 敵の弾の最大数
	static constexpr int ENEMY_BULLET_MAX = 3;

	// データメンバの宣言 -----------------------------------------------
private:

	// ゲームの状態
	GameState m_gameState;

	// タスクマネージャー
	Imase::TaskManager m_taskManager;

	// Gameへのポインタ
	Game* m_pGame;

	// 絵のグラフィックハンドル
	int m_ghTexture;

	// プレイヤーへのポインタ
	Player* m_pPlayer;

	// 敵のマネージャーへのポインタ
	EnemyManager* m_pEnemyManager;

	// プレイヤーの弾のマネージャーへのポインタ
	BulletManager* m_pPlayerBulletManager;

	// 敵の弾のマネージャーへのポインタ
	BulletManager* m_pEnemyBulletManager;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	GamePlayScene(Game* pGame);

	// デストラクタ
	~GamePlayScene();

	// 初期化処理
	void Initialize() override;

	// 更新処理
	void Update(float elapsedTime) override;

	// 描画処理
	void Render() override;

	// 終了処理
	void Finalize() override;

private:

	// プレイヤーの移動
	void MovePlayer();

	// 敵と弾との衝突判定
	void CheckEnemiesColliedWithBullets(const std::vector<Enemy*>& enemies, const std::vector<Bullet*>& bullets);

	// プレイヤーと弾との衝突判定
	void CheckPlayerColliedWithBullets(Player* player, const std::vector<Bullet*>& bullets);

};
