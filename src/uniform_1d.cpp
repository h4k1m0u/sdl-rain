#include "uniform_1d.hpp"

Uniform1D::Uniform1D(int min, int max):
  m_seed(std::random_device()),
  m_generator(m_seed()),
  m_uniform(min, max)
{
}

Uniform1D::Uniform1D(const std::pair<int, int>& bounds):
  Uniform1D(bounds.first, bounds.second)
{
}

int Uniform1D::get_random_int() {
  return m_uniform(m_generator);
}

SDL_Color Uniform1D::get_random_color() {
  Uint8 red = static_cast<Uint8>(get_random_int());
  Uint8 green = static_cast<Uint8>(get_random_int());
  Uint8 blue = static_cast<Uint8>(get_random_int());
  SDL_Color color = { red, green, blue, 0xff };

  return color;
}
