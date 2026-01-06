#include "drop.hpp"
#include "constants.hpp"
#include "uniform_1d.hpp"

constexpr std::pair<int, int> X_BOUNDS(0, Constants::WINDOW_WIDTH);
constexpr std::pair<int, int> Y_BOUNDS(-500, -100);
constexpr std::pair<int, int> LENGTH_BOUNDS(10, 20);
constexpr std::pair<int, int> SPEED_Y_BOUNDS(10, 20);

Drop::Drop():
  m_x(Uniform1D(X_BOUNDS).get_random_int()),
  m_y(Uniform1D(Y_BOUNDS).get_random_int()),
  m_length(Uniform1D(LENGTH_BOUNDS).get_random_int()),
  m_speed_y(Uniform1D(SPEED_Y_BOUNDS).get_random_int())
{
}

void Drop::fall() {
  m_y += m_speed_y;

  // redraw drop above window once beyond window-height
  if (m_y > Constants::WINDOW_HEIGHT) {
    m_y = Uniform1D(SPEED_Y_BOUNDS).get_random_int();
  }
}

void Drop::draw(SDL_Renderer* renderer, const SDL_Color& color) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 0xff);
  SDL_RenderDrawLine(renderer, m_x, m_y, m_x, m_y + m_length);
}
