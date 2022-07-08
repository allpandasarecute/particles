#include "particle.h"
#include "raylib.h"

int main(void) {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800, 450, "raylib [core] example - keyboard input");

	Vector2 ballPosition = {(float)800 / 2, (float)450 / 2};


	SetTargetFPS(120);

	while (!WindowShouldClose()) {
		if (IsKeyDown(KEY_RIGHT) && ballPosition.x + 50 < GetScreenWidth())
			ballPosition.x += 1.0f;
		if (IsKeyDown(KEY_LEFT) && ballPosition.x - 50 > 0)
			ballPosition.x -= 1.0f;
		if (IsKeyDown(KEY_UP) && ballPosition.y - 50 > 0)
			ballPosition.y -= 1.0f;
		if (IsKeyDown(KEY_DOWN) && ballPosition.y + 50 < GetScreenHeight())
			ballPosition.y += 1.0f;

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

		DrawFPS(10, 30);

		DrawCircleV(ballPosition, 50, PURPLE);

		EndDrawing();
	}


	CloseWindow();

	return 0;
}
