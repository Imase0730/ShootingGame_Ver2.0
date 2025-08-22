//--------------------------------------------------------------------------------------
// File: Explosion.cpp
//
//--------------------------------------------------------------------------------------
#include "Explosion.h"

// コンストラクタ
Explosion::Explosion(Vector2D position, int ghTexture)
	: m_position{ position }
	, m_ghTexture{ ghTexture }
	, m_animationState{ AnimationState::Anim01 }
	, m_animationCounter{ 0 }
{
}

// 更新処理
bool Explosion::Update(float elapsedTime)
{
	// アニメーションカウンターを加算
	m_animationCounter++;

	if (m_animationCounter > ANIMATION_INTERVAL)
	{
		// アニメーションカウンターをリセットする
		m_animationCounter = 0;

		// 爆発の最後の絵ならアニメーションを終了する
		if (m_animationState == AnimationState::Anim04)
		{
			// エフェクトを消す
			return false;
		}
		else
		{
			// 次の絵に変更する
			m_animationState = static_cast<AnimationState>(static_cast<int>(m_animationState) + 1);
		}
	}

	return true;
}

// 描画処理
void Explosion::Render()
{
	// スプライトシート上の絵の位置を取得
	int x = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].x;
	int y = EXPLOSION_SPRITES[static_cast<int>(m_animationState)].y;

	// 爆発の描画
	DrawRectRotaGraph(static_cast<int>(m_position.x), static_cast<int>(m_position.y)
		, x, y, 16, 16, SIZE / 16, 0.0f, m_ghTexture, TRUE);
}

