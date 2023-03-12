#ifdef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include<CommonFunction.h>

class BaseObject
{
public :
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {rect.x = x, rect.y = y;}
    // ham set kich thuoc cho rect
    SDL_Rect GetRect() const {return rect_;}
    SDL_Texture* GetObject() const {return p_object_;}

    bool LoadImage(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des , const SDl_Rect* clip = NUlL)


protected:
    SDL_Texture* p_object_;
    // bien luu tru hinh anh
    SDL_Rect rect_;
    // bien luu kich thuoc anh
};
#endif // BASE_OBJECT

