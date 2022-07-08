#include "particle.h"

#include "constants.h"
#include "raylib.h"

void move(particle *p) {
	p->position.x += p->velocity.x;
	p->position.y += p->velocity.y;

	if (p->position.x < 0)
		p->position.x += windowWidth;
	if (p->position.x > windowWidth)
		p->position.x -= windowWidth;

	if (p->position.y < 0)
		p->position.y += windowHeight;
	if (p->position.y > windowHeight)
		p->position.y -= windowHeight;
}

float getDistance(particle *p, Vector2 *other) {
	return (other->x - p->position.x) * (other->x - p->position.x) + (other->y - p->position.y) * (other->y - p->position.y);
}

void newVelocity(particle *p, Vector2 *mousePosition) {
	float dist = getDistance(p, mousePosition);
	p->velocity.x += GRAVITY * (mousePosition->x - p->position.x) / dist;
	p->velocity.y += GRAVITY * (mousePosition->y - p->position.y) / dist;
}

void multiplyVelocity(particle *p, float multiplier) {
	p->velocity.x *= multiplier;
	p->velocity.y *= multiplier;
}