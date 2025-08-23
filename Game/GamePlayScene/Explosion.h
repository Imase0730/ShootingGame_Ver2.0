//--------------------------------------------------------------------------------------
// File: Explosion.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "Game/Common/GameMath.h"
#include "Game/Common/TaskManager.h"

// 爆発クラス
class Explosion : public Imase::Task
{
private:

	// 爆発のアニメーションステート
	enum class AnimationState
	{
		AnimNone = -1,
		Anim01, Anim02, Anim03, Anim04,
	};

private:

	// 爆発アニメーションの間隔
	static constexpr int ANIMATION_INTERVAL = 4;

	// 爆発の表示の大きさ
	static constexpr float SIZE = 64.0f;

	// 爆発のスプライトシート上の絵の位置
	static constexpr POINT EXPLOSION_SPRITES[] =
	{
		{ 96 + 16 * 0, 32 },		// パターン１
		{ 96 + 16 * 1, 32 },		// パターン２
		{ 96 + 16 * 2, 32 },		// パターン３
		{ 96 + 16 * 3, 32 },		// パターン４
	};

private:

	// 表示位置
	Vector2D m_position;

	// グラフィックハンドル
	int m_ghTexture;

	// アニメーションステート
	AnimationState m_animationState;

	// 爆発のアニメーションカウンター
	int m_animationCounter;

public:

	// コンストラクタ
	Explosion(Vector2D position, int ghTexture);

	// 更新処理
	bool Update(float elapsedTime) override;

	// 描画処理
	void Render() override;

};

