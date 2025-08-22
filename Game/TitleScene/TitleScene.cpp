//--------------------------------------------------------------------------------------
// File: TitleScene.cpp
//
//--------------------------------------------------------------------------------------
#include "TitleScene.h"
#include "Game/Game.h"

// コンストラクタ
TitleScene::TitleScene(Game* pGame)
	: Scene(pGame->GetSceneManager())
	, m_pGame(pGame)
{

}

// デストラクタ
TitleScene::~TitleScene()
{
}

// 初期化処理
void TitleScene::Initialize()
{
}

// 更新処理
void TitleScene::Update(float elapsedTime)
{
	int keyTrigger = m_pGame->GetKeyTrigger();

	// スペースキーでゲームスタート
	if (keyTrigger & PAD_INPUT_10)
	{
		ChangeScene("GamePlay");
	}
}

// 描画処理
void TitleScene::Render()
{
	// ゲームタイトルの表示
	DrawFormatString(Screen::WIDTH / 2 - GetDrawStringWidth(TITLE, static_cast<int>(wcslen(TITLE))) / 2
		, Screen::HEIGHT / 2 - Game::FONT_SIZE / 2
		, GetColor(255, 255, 255), TITLE);
}

// 終了処理
void TitleScene::Finalize()
{
}

