#pragma once
#include <raylib.h>
inline Vector2 operator*(Vector2 &lhs, int scalar) {
  Vector2 temp;
  temp.x = lhs.x * scalar;
  temp.y = lhs.y * scalar;
  return temp;
}
class Layer {
private:
  Vector2 pos_start_vertical;
  Vector2 pos_end_vertical;
  Vector2 pos_start_horizontal;
  Vector2 pos_end_horizontal;
  Vector2 mouse;
  float v_gap;
  float h_gap;
  Vector2 draw_coord;
  int board[3][3];
  bool turn = 0;
  bool showMessageBox;
  int game_won_by;
  int center_x;
  int center_y;

public:
  Layer();
  ~Layer();
  void on_attach();
  void on_detach();
  void on_update();
  void on_draw();
  int check_win();
  int check_draw();
  bool game_over;
};
