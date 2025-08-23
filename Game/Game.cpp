/**
 * @file   Game.cpp
 *
 * @brief  ゲーム全体に関するソースファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// ヘッダファイルの読み込み ===================================================
#include "Game.h"

#include "Game/Screen.h"




// メンバ関数の定義 ===========================================================
/**
 * @brief デフォルトコンストラクタ
 *
 * @param なし
 */
Game::Game()
	: m_key{ 0 }
	, m_oldKey{ 0 }
	, m_keyCondition{ 0 }
	, m_keyTrigger{ 0 }
	, m_sceneManager{}
{
	// 乱数の初期値を設定
	SRand(static_cast<int>(time(nullptr)));
}



/**
 * @brief デストラクタ
 */
Game::~Game()
{

}



/**
 * @brief 初期化処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Initialize()
{
	// 文字のサイズを変更する
	SetFontSize(FONT_SIZE);

	// シーンの登録
	m_sceneManager.RegisterScene("Title", std::make_unique<TitleScene>(this));
	m_sceneManager.RegisterScene("GamePlay", std::make_unique<GamePlayScene>(this));

	// ゲームの初期化
	m_sceneManager.SetStartScene("Title");
}



/**
 * @brief 更新処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Update(float elapsedTime)
{
	// キー入力の取得
	m_oldKey = m_key;
	m_key    = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	// キーコンディション
	m_keyCondition = m_key;

	// キートリガー
	m_keyTrigger = ~m_oldKey & m_key;

	// ゲームの更新
	m_sceneManager.Update(elapsedTime);
}



/**
 * @brief 描画処理
 *
 * @param[in] なし
 *
 * @return なし
 */
void Game::Render()
{
	// ゲームの描画
	m_sceneManager.Render();
}


/**
 * @brief 終了処理
 *
 * @param なし
 *
 * @return なし
 */
void Game::Finalize()
{
	// ゲームの終了処理
}
