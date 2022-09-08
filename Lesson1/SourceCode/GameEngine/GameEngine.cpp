// GameEngine.cpp : Defines the entry point for the application.
//

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "GameEngine.h"
#include "RenderEngine.h"

int counter = 0;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // Enable run-time memory check for debug builds.
#if defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    std::unique_ptr<CRenderEngine> renderEngine = std::make_unique<CRenderEngine>(hInstance);

    MSG msg = { 0 };
    //Cube cube;
    /*cube.set_pos({
            {-1.0f,  1.0f,  1.0f, 0xff000000 },
            { 1.0f,  1.0f,  1.0f, 0xff0000ff },
            {-1.0f, -1.0f,  1.0f, 0xff00ff00 },
            { 1.0f, -1.0f,  1.0f, 0xff00ffff },
            {-1.0f,  1.0f, -1.0f, 0xffff0000 },
            { 1.0f,  1.0f, -1.0f, 0xffff00ff },
            {-1.0f, -1.0f, -1.0f, 0xffffff00 },
            { 1.0f, -1.0f, -1.0f, 0xffffffff },
        });*/
    // Main message loop:
    while (msg.message != (WM_QUIT | WM_CLOSE))
    {
        counter++;
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            renderEngine->Update(counter);
        }
    }

    return (int) msg.wParam;
}
