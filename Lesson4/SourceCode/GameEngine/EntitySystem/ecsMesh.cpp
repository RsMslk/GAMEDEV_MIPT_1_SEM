#include "ecsMesh.h"
#include "ecsSystems.h"
#include "ecsPhys.h"
#include "flecs.h"
#include "RenderThread.h"
#include "RenderEngine.h"
#include "CubeRenderProxy.h"

void register_ecs_mesh_systems(flecs::world &ecs)
{
    static auto render_Cubes_Query = ecs.query<RenderEnginePtr, CubeMesh>();
    static auto render_Small_Cubes_Query = ecs.query<RenderEnginePtr, SmallCubeMesh>();

    ecs.system<const CubeMesh>()
    .each([&](flecs::entity e, const CubeMesh& cubeMesh)
    {
      render_Cubes_Query.each([&](RenderEnginePtr re, CubeMeshes& cube_Meshes)
      {
          RenderProxy* renderProxy = nullptr;
          for (auto mesh: cube_Meshes.Cube_Meshes)
          {
              if(!mesh->)
          }

          float position[3];
          position[0] = 0.0f;
          position[1] = 0.0f;
          position[2] = 0.0f;

          renderProxy->SetPosition(position);

          e.set(RenderProxyPtr{ renderProxy });
          e.remove<CubeMesh>();
      });
    });

  ecs.system<const SmallCubeMesh>()
      .each([&](flecs::entity e, const SmallCubeMesh& cubeMesh)
          {
              renderQuery.each([&](RenderEnginePtr re)
                  {
                      RenderProxy* renderProxy = new CubeRenderProxy;
                      re.ptr->GetRT()->EnqueueCommand(RC_CreateCubeRenderObject, renderProxy);

                      float position[3];
                      position[0] = 0.0f;
                      position[1] = 0.0f;
                      position[2] = 0.0f;

                      renderProxy->SetPosition(position);

                      e.set(RenderProxyPtr{ renderProxy });
                      e.remove<CubeMesh>();
                  });
          });

  ecs.system<RenderProxyPtr, const Position>()
    .each([&](RenderProxyPtr &renderProxy, const Position &pos)
    {
      renderQuery.each([&](RenderEnginePtr re)
      {
           float position[3];
           position[0] = pos.x;
           position[1] = pos.y;
           position[2] = pos.z;

           renderProxy.ptr->SetPosition(position);
      });
    });
}

