#ifndef PADDLE
#define PADDLE

#include <raylib-cpp.hpp>
using namespace raylib;

class Paddle
{
public:
  float x, y;
  float width, height;
  int speed;

  void Draw();
  void Update(Window &window);

protected:
  void LimitMovement(Window &window);
};

class CpuPaddle : public Paddle
{
public:
  void Update(int ball_y, Window &window);
};

#endif /* PADDLE */
