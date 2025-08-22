/**
 * @file   Game.h
 *
 * @brief  ゲーム全体に関するヘッダファイル
 *
 * @author 制作者名
 *
 * @date   日付
 */

// 多重インクルードの防止 =====================================================
#pragma once




// ヘッダファイルの読み込み ===================================================

#include "SceneManager.h"
#include "TitleScene/TitleScene.h"
#include "GamePlayScene/GamePlayScene.h"

// クラスの宣言 ===============================================================




// クラスの定義 ===============================================================
/**
 * @brief ゲーム
 */
class Game
{
// クラス定数の宣言 -------------------------------------------------
public:
	// システム関連
	static constexpr const wchar_t* TITLE = L"Shooting Game";   ///< ゲームタイトル

	// 文字のサイズ
	static constexpr int FONT_SIZE = 50;


// データメンバの宣言 -----------------------------------------------
private:
	// 入力関連
	int m_key;       ///< 現在のキー情報
	int m_oldKey;    ///< 前回のキー情報

	// キー情報（コンディション）
	int m_keyCondition;

	// キー情報（トリガー）
	int m_keyTrigger;

	// シーンマネージャー
	SceneManager m_sceneManager;

// メンバ関数の宣言 -------------------------------------------------
// コンストラクタ/デストラクタ
public:
	// コンストラクタ
	Game();

	// デストラクタ
	~Game();


// 操作
public:
	// 初期化処理
	void Initialize();

	// 更新処理
	void Update(float elapsedTime);

	// 描画処理
	void Render();

	// 終了処理
	void Finalize();

	// シーンマネージャーを取得する関数
	SceneManager* GetSceneManager() { return &m_sceneManager; }

	// キー情報を取得する関数（コンディション）
	int GetKeyCondition() const { return m_keyCondition; }

	// キー情報を取得する関数（トリガー）
	int GetKeyTrigger() const { return m_keyTrigger; }

};
