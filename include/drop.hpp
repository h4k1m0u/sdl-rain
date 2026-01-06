#ifndef DROP_HPP
#define DROP_HPP

#include <SDL2/SDL_render.h>

class Drop {
public:
  Drop();
  void fall();
  void draw(SDL_Renderer* renderer, const SDL_Color& color);

private:
  int m_x;
  int m_y;
  int m_length;
  int m_speed_y;
};

#endif
