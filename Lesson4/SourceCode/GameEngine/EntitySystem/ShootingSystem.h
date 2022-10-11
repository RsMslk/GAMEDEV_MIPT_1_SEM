#pragma once
#include "flecs.h"

struct Shooted {};
typedef bool Shooting;
//struct ShootDirection { float x, y, z; };

void register_ecs_shooting_systems(flecs::world& ecs);
