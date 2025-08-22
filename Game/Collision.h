//--------------------------------------------------------------------------------------
// File: Collision.h
//
//--------------------------------------------------------------------------------------
#pragma once

#include "GameMath.h"

// ‰~‚Ìî•ñ
struct BoundingCircle
{
	// ’†S
	Vector2D center;

	// ”¼Œa
	float radius;
};

// ‰~‚Æ‰~‚ÌÕ“Ë”»’è
inline bool IsCircleColliding(const BoundingCircle& a, const BoundingCircle& b)
{
	if (Length(a.center - b.center) <= a.radius + b.radius) return true;
	return false;
}

// ‰~‚Æ‰~‚ªd‚È‚ç‚È‚¢—p‚ÉˆÊ’u‚ğ•â³‚·‚éŠÖ”
inline void ResolveOverlap(BoundingCircle* a, BoundingCircle* b)
{
    Vector2D delta = b->center - a->center;
    float dist = Length(delta);
    float minDist = a->radius + b->radius;

    // ‚Q‚Â‚Ì‰~‚ğd‚È‚ç‚È‚¢—p‚ÉˆÚ“®‚·‚é
    float overlap = minDist - dist;
    if (overlap > 0.0f)
    {
        Vector2D correction = Normalize(delta) * (overlap / 2.0f);
        a->center -= correction;
        b->center += correction;
    }
}
