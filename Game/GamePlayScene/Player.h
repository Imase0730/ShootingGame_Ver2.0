//--------------------------------------------------------------------------------------
// File: Play.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/GameObject.h"

// プレイヤークラス
class Player : public GameObject
{
	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr float SIZE = 64.0f;

	// 半径
	static constexpr float RADIUS = SIZE / 2.0f;

	// 移動の速さ
	static constexpr float SPEED = 5.0f;

	// データメンバの宣言 -----------------------------------------------
private:

	// グラフィックハンドル
	int m_ghTexture;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Player(int ghTexture);

	// 更新関数
	bool Update(float elapsedTime) override;

	// 描画関数
	void Render() override;

	// 移動を停止する関数
	void MoveStop();

	// 左に移動する関数
	void MoveLeft();

	// 右に移動する関数
	void MoveRight();

};
