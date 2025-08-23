//--------------------------------------------------------------------------------------
// File: TitleScene.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/Common/Scene.h"
#include "Game/Screen.h"

// クラスの前方宣言
class Game;

// タイトルシーン
class TitleScene : public Scene
{

	// クラス定数の宣言 -------------------------------------------------
public:

	// タイトルの文字列
	static constexpr wchar_t TITLE[] = L"Shooting Game";

	// データメンバの宣言 -----------------------------------------------
private:

	// Gameへのポインタ
	Game* m_pGame;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	TitleScene(Game* pGame);

	// デストラクタ
	~TitleScene();

	// 初期化処理
	void Initialize() override;

	// 更新処理
	void Update(float elapsedTime) override;

	// 描画処理
	void Render() override;

	// 終了処理
	void Finalize() override;

};
