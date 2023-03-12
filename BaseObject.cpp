#include<BaseObject.h>

BaseObject::BaseObject()
{
    p_object_ = NULL;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0;
}

BaseObject::~BaseObject()

bool BaseObject:: LoadImage(std::string path , SDL_Renderer* screen)
