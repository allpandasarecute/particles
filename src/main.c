#include <stdlib.h>

#include "constants.h"
#include "particle.h"
#include "raylib.h"

int main(void) {
	particle *particles = (particle *)malloc(particleCount * sizeof(particle));
	for (int i = 0; i < particleCount; ++i) {
		particles[i].position.x = rand() % windowWidth;
		particles[i].position.y = rand() % windowHeight;
		particles[i].velocity.x = ((float)rand() - RAND_MAX / 2) / (3 * (float)RAND_MAX);
		particles[i].velocity.y = ((float)rand() - RAND_MAX / 2) / (3 * (float)RAND_MAX);
	}

	Vector2 mousePosition;

	InitWindow(windowWidth, windowHeight, "Particles");
	SetWindowIcon(LoadImage("icon.png"));
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		mousePosition = GetMousePosition();

		BeginDrawing();

		ClearBackground(WHITE);

		// DrawFPS(10, 10);

		for (int i = 0; i < particleCount; ++i) {
			DrawPixelV(particles[i].position, BLACK);
			newVelocity(particles + i, &mousePosition);
			multiplyVelocity(particles + i, 0.99);
			move(particles + i);
		}

		EndDrawing();
	}

	CloseWindow();

	free(particles);

	return 0;
}
