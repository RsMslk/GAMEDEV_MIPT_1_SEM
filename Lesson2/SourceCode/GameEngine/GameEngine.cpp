// GameEngine.cpp : Defines the entry point for the application.
//

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "GameEngine.h"
#include "RenderEngine.h"
#include "RenderThread.h"
#include "CubeGameObject.h"
#include "GameTimer.h"


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    GameTimer timer;

    RenderEngine* renderEngine = new RenderEngine(hInstance);
    RenderThread* renderThread = renderEngine->GetRT();

    GameObject* cube = new CubeGameObject();
    renderThread->EnqueueCommand(RC_CreateCubeRenderObject, cube->GetRenderProxy());

    MSG msg = { 0 };

    timer.Start();
    timer.Reset();

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
            //float t = 0;
            timer.Tick();
            bool right_key = GetAsyncKeyState(VK_RIGHT);
            bool down_key = GetAsyncKeyState(VK_DOWN);
            bool up_key = GetAsyncKeyState(VK_UP);
            bool left_key = GetAsyncKeyState(VK_LEFT);
            bool shift_key = GetAsyncKeyState(VK_LSHIFT);
            bool ctrl_key = GetAsyncKeyState(VK_LCONTROL);
            //t = sin(timer.TotalTime())*2;
            if (right_key)
            {
                cube->SetPosition(cube->Get_X() + 0.1, cube->Get_Y(), cube->Get_Z());
                //right_key = 0;
            }
            if (left_key)
            {
                cube->SetPosition(cube->Get_X() - 0.1, cube->Get_Y(), cube->Get_Z());
                //left_key = 0;
            }
            if (down_key)
            {
                cube->SetPosition(cube->Get_X(), cube->Get_Y() - 0.1, cube->Get_Z());
                //down_key = 0;
            }
            if (up_key)
            {
                cube->SetPosition(cube->Get_X(), cube->Get_Y() + 0.1, cube->Get_Z());
                //up_key = 0;
            }
            if (shift_key)
            {
                cube->SetPosition(cube->Get_X(), cube->Get_Y() , cube->Get_Z() - 0.1);
                //shift_key = 0;
            }
            if (ctrl_key)
            {
                cube->SetPosition(cube->Get_X(), cube->Get_Y() , cube->Get_Z() + 0.1);
                //ctrl_key = 0;
            }


            renderThread->OnEndFrame();
        }
    }

    return (int) msg.wParam;
}
