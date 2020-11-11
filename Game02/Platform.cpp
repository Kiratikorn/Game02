#include "Platform.h"

void Platform::init(float X, float Y, float W, float H)
{
	hitbox.left = X + 0.f;
	hitbox.right = X + 120.f;
	hitbox.top = Y + 0.f;
	hitbox.bottom = Y + 120.f;

}
