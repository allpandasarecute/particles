#include <stdlib.h>

#include "particle.h"
#include "raylib.h"

int main(void) {
	const int particleCount = 100000;
	particle *particles = (particle *)malloc(particleCount * sizeof(particle));
	Vector2 mousePosition;

	InitWindow(800, 800, "Particles");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawFPS(10, 10);

		EndDrawing();
	}

	CloseWindow();

	free(particles);

	return 0;
}
