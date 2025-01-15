#pragma once
#include <cmath>

// 円形の当たり判定関数
inline bool IsCircleHit(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x1 - x2;
    int dy = y1 - y2;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSum = r1 + r2;
    return distanceSquared <= (radiusSum * radiusSum);
}