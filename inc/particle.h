#ifndef PARTICLE_H
#define PARTICLE_H

#include "raylib.h"

typedef struct particle {
		Vector2 position;
		Vector2 velocity;
} particle;

void move(particle *p);
void newVelocity(particle *p, Vector2 *mousePosition);
float getDistance(particle *p, Vector2 *other);
void multiplyVelocity(particle *p, float multiplier);

#endif  // PARTICLE_H