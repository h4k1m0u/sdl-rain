#ifndef UNIFORM_1D_HPP
#define UNIFORM_1D_HPP

#include <random>
#include <SDL2/SDL_pixels.h>

class Uniform1D {
public:
  Uniform1D(int min, int max);
  Uniform1D(const std::pair<int, int>& bounds);
  int get_random_int();
  SDL_Color get_random_color();

private:
  std::random_device m_seed;
  std::mt19937 m_generator;
  std::uniform_int_distribution<int> m_uniform;
};

#endif
