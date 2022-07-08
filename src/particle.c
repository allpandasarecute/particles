#include "particle.h"

#include "raylib.h"
#include "raymath.h"

void addVelocity(particle *p) {
	p->position = Vector2Add(p->position, p->velocity);
}