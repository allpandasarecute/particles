#ifndef PARTICLE_H_
#define PARTICLE_H_

#include "raylib.h"

typedef struct particle particle;

struct particle {
		Vector2 position;
		Vector2 velocity;
};

#endif  // PARTICLE_H