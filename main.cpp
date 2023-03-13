
#include"commonfunction.h"
#include"BaseObject.h"
BaseObject g_background;
bool InitData()
{
    bool success = true;
    // bien tra ve
    int ret = SDL_Init(SDL_INIT_VIDEO);
    // thiet lap moi truong ban dau cho sdl
    if (ret < 0)
    // ham chay co loi hay init ko thanh cong
        return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    //thiet lap che do ti le va chat luong

    g_window = SDL_CreateWindow("Gamecpp SLD2.0",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    // tao cua so window
    if(g_window=NULL)
    {
        return false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window,-1,SDL_RENDERER_ACCELERATED);
        // g_window tra bien render cho screen
        if (g_screen = NULL)
        {
            return false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags)&&imgFlags))
            {
                success = false;
            }
        }
    }
    return success;
}

bool loadBackGround()
{
    bool ret = g_background.LoadImage("image\\background1.png",g_screen);
    if (ret == false)
        return false;

    return true;
}

void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();

}
int main(int argc, char* argv[])
{
    if (InitData() == false )
    {return -1;}
    if (loadBackGround()==false)
    {return -1;}

    bool is_quit = false;
    while (!is_quit)
    {
        while(SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;

            }
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR,RENDER_DRAW_COLOR,RENDER_DRAW_COLOR);
        // cho ca screen bang mau do roi xoa di
        SDL_RenderClear(g_screen);
        // truoc khi load anh thi phai set lai mau cho man hinh roi xoa di de lam moi

        g_background.Render(g_screen, NULL);
        SDL_RenderPresent(g_screen);
    }
    close();
    return 0;
}
