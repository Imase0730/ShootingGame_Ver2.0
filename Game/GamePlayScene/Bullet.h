//--------------------------------------------------------------------------------------
// File: Bullet.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "GameObject.h"

// 弾クラス
class Bullet : public GameObject
{
	// 列挙型の定義 -----------------------------------------------------
public:

	// 弾のタイプ
	enum class Type { None, Player, Enemy, TypeMax };

	// クラス定数の宣言 -------------------------------------------------
public:

	// 大きさ
	static constexpr float SIZE = 16.0f;

	// 半径
	static constexpr float RADIUS = SIZE / 2.0f;

	// データメンバの宣言 -----------------------------------------------
private:

	// グラフィックハンドル
	int m_ghTexture;

	// タイプ
	Type m_type;

	// メンバ関数の宣言 -------------------------------------------------
public:

	// コンストラクタ
	Bullet();

	// 更新関数
	bool Update(float elapsedTime) override;

	// 描画関数
	void Render() override;

	// 弾を発射する関数
	void Shoot(Vector2D position, Vector2D velocity, int ghTexture, Type type);

};
