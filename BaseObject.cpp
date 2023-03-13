#include "BaseObject.h"

BaseObject::BaseObject()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}

BaseObject::~BaseObject()
{
    Free();
}

bool BaseObject:: LoadImage(std::string path , SDL_Renderer* screen)
{
    SDL_Texture* new_texture = NULL;
    //bien ket qua
    SDL_Surface* load_surface = IMG_Load(path.c_str());
    //hamf img load tra ve 1 surface
    if (load_surface != NULL)
    {
        SDL_SetColorKey(load_surface, SDL_TRUE, SDL_MapRGB(load_surface->format, COLOR_KEY_R,COLOR_KEY_G,COLOR_KEY_B));
        new_texture = SDL_CreateTextureFromSurface(screen, load_surface);
        if (new_texture!=NULL)
        {
            rect_.w = load_surface->w;
            rect_.h = load_surface->h;
        }
        SDL_FreeSurface(load_surface);
    }
        p_object_ = new_texture;
        return p_object_ != NULL;
    // neu p object khac NULL return 1; con bang null return 0;
}


void BaseObject:: Render(SDL_Renderer* des,const SDL_Rect* clip /* = NULL */)
// des bien dung de up anh len doi tuong nao
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w , rect_.h};

    SDL_RenderCopy(des, p_object_, clip, &renderquad);
}

void BaseObject :: Free()
{
    if (p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w =0 ;
        rect_.h=0 ;
    }
}
