 #pragma once
#include "flecs.h"
#include <vector>

struct Display_On {};

struct CubeMesh {};
struct SmallCubeMesh {};

struct RenderProxyPtr
{
	class RenderProxy* ptr;
};
struct DestructionTimer {
	float Curr_Time;
	float Time_Passed = 0;
};

struct CubeMeshes
{
	std::vector<RenderProxy*> Cube_Meshes;
};

struct SmallCubeMeshes
{
	std::vector<RenderProxy*> Small_Cube_Meshes;
};

void register_ecs_mesh_systems(flecs::world &ecs);

