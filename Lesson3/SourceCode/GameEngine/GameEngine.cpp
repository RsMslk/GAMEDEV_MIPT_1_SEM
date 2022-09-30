// GameEngine.cpp : Defines the entry point for the application.
//

#if defined(DEBUG) || defined(_DEBUG)
#define HI 5.0f
#define LO -5.0f
const float RAND_MAX = 10.0;
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif



#include "GameEngine.h"
#include "RenderEngine.h"
#include "RenderThread.h"
#include "CubeGameObject.h"
#include "GameTimer.h"
#include "InputHandler.h"
#include <vector>
#include <cstdlib>
#include <ctime>

float rand_float() {
   return LO + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(HI - LO)));
}


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    srand(static_cast <unsigned> (time(0)));
    GameTimer timer;

    RenderEngine* renderEngine = new RenderEngine(hInstance);
    RenderThread* renderThread = renderEngine->GetRT();
    InputHandler* inputHandler = new InputHandler();
    
    std::vector <GameObject*> cubes;
    
    for (int i = 0; i < 100; i++)
    {
        cubes.push_back(new CubeGameObject());
    }

    MSG msg = { 0 };

    timer.Start();
    timer.Reset();
    float g = 9.8f;
    for (int i = 0; i < cubes.size(); i ++)
    {
        cubes[i]->SetMass(2.0);
        cubes[i]->SetPosition(rand_float(), abs(rand_float()), rand_float());
        cubes[i]->SetVelocity(0.0, 0.0, 0.0);
        
        cubes[i]->SetType(rand()%1); // 0 - physics on, 1 - movement tuda-suda, 2 - controls on
        renderThread->EnqueueCommand(RC_CreateCubeRenderObject, cubes[i]->GetRenderProxy());
        if (cubes[i]->Get_Type() == 0) {
            cubes[i]->SetAcceleration(0.0, -g, 0.0);
        }

    }
    float elasticity = 0.7f;
    // Main message loop:
    while (msg.message != (WM_QUIT | WM_CLOSE))
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            inputHandler->Update();
           
            float t = 0;
            timer.Tick();
            t = timer.TotalTime();
            for (int j = 0; j < cubes.size(); j++)
            {
                float newPos[3] = { cubes[j]->Get_X(), cubes[j]->Get_Y(), cubes[j]->Get_Z()};
                float velocity[3] = { cubes[j]->Get_Vx(), cubes[j]->Get_Vy(), cubes[j]->Get_Vz() };
                float acceleration[3] = { cubes[j]->Get_Ax(), cubes[j]->Get_Ay(), cubes[j]->Get_Az() };
                
                if (cubes[j]->Get_Type() == 0)
                {
                    
                    float impulse[3];
                    float mass = cubes[j]->Get_M();
                    if (cubes[j]->Get_Y() > 0)
                    {
                        for (int i = 0; i < 3; i++) {
                            velocity[i] = velocity[i] + acceleration[i] * timer.DeltaTime();
                            impulse[i] = mass * velocity[i];
                        }
                    }
                    else if (cubes[j]->Get_Y() <= 0 && velocity[1] < 0)
                    {
                        velocity[1] = -velocity[1] * elasticity;
                    } 
                    if (velocity[0] * velocity[0] + velocity[1] * velocity[1] + velocity[2] * velocity[2] < 0.01 && (cubes[j]->Get_Y()) < 0.01)
                    {
                        velocity[1] += 10.0f;
                    }

                }
                else if (cubes[j]->Get_Type() == 1) {
                    velocity[0] = sin(t);                    
                }
                else
                {
                    if (inputHandler->GetInputState().test(eIC_GoLeft))
                        velocity[0] -= 1.0f;
                    if (inputHandler->GetInputState().test(eIC_GoRight))
                        velocity[0] += 1.0f;
                }
                for (int i = 0; i < 3; i++)
                {
                    newPos[i] += velocity[i] * timer.DeltaTime();
                }
                cubes[j]->SetPosition(newPos[0], newPos[1], newPos[2]);
                cubes[j]->SetVelocity(velocity[0], velocity[1], velocity[2]);
                cubes[j]->SetAcceleration(acceleration[0], acceleration[1], acceleration[2]);
                
            }
            
            renderThread->OnEndFrame();
        }
    }

    return (int) msg.wParam;
}
