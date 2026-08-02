#include "Core/Layer.hpp"
#include "Math/Vec2.hpp"

#define RAYGUI_IMPLEMENTATION
#include "raygui/raygui.h"

Layer::Layer() : game_over{false} {
  ChangeDirectory(GetApplicationDirectory());
}
Layer::~Layer() {}

void Layer::on_attach() {
  InitWindow(720, 720, "NN-VISUALIZER");
  if (IsWindowReady()) {
    int width = GetScreenWidth();
    int height = GetScreenHeight();
    center_x = width / 2;
    center_y = height / 2;
    h_gap = (width / 3.0f);
    v_gap = height / 3.0f;
    pos_start_vertical = Vector2(v_gap, 0);
    pos_end_vertical = Vector2(v_gap, width);
    pos_start_horizontal = Vector2(0, h_gap);
    pos_end_horizontal = Vector2(width, h_gap);

  } else {
  }
}

void Layer::on_detach() { CloseWindow(); }

int Layer::check_win() {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != 0 && board[i][0] == board[i][1] &&
        board[i][1] == board[i][2]) {
      game_over = true;
      return board[i][0];
    }
  }

  for (int j = 0; j < 3; j++) {
    if (board[0][j] != 0 && board[0][j] == board[1][j] &&
        board[1][j] == board[2][j]) {
      game_over = true;

      return board[0][j];
    }
  }
  if (board[0][0] != 0 && board[0][0] == board[1][1] &&
      board[1][1] == board[2][2]) {
    game_over = true;

    return board[0][0];
  }
  if (board[0][2] != 0 && board[0][2] == board[1][1] &&
      board[1][1] == board[2][0]) {
    game_over = true;

    return board[0][2];
  }

  return 0;
}

void Layer::on_update() {
  mouse = GetMousePosition();
  // std::cout << mouse.x << "," << mouse.y << "\n";
  //
  bool pressed = IsMouseButtonPressed(0);

  if (pressed && !game_over) {

    Vector2 instance = GetMousePosition();
    Vec2 pos(int(instance.x / h_gap), int(instance.y / v_gap));

    if (board[pos.x][pos.y] == 0) {

      board[pos.x][pos.y] = (turn == 0) ? 1 : 2;

      turn = !turn;
    }
    int win = check_win();
    int draw = check_draw();
    if (win != 0) {
      game_won_by = win;
      showMessageBox = true;
    }
  }
}

int Layer::check_draw() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
        return 0;
      }
    }
  }
  game_over = true;
  return 1;
}
void Layer::on_draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  const float thickness = 10.0;
  DrawLineEx(pos_start_vertical, pos_end_vertical, thickness, WHITE);
  DrawLineEx(pos_start_horizontal, pos_end_horizontal, thickness, WHITE);
  DrawLineEx(pos_start_vertical * 2, pos_end_vertical * 2, thickness, WHITE);
  DrawLineEx(pos_start_horizontal * 2, pos_end_horizontal * 2, thickness,
             WHITE);
  DrawCircle(float(mouse.x), float(mouse.y), 5.0, WHITE);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

      draw_coord = {(i * h_gap + h_gap / 2), (j * v_gap + v_gap / 2)};
      if (board[i][j] == 1) {

        DrawCircle(float(draw_coord.x), float(draw_coord.y), 20.0, WHITE);
      } else if (board[i][j] == 2) {
        DrawCircle(float(draw_coord.x), float(draw_coord.y), 20.0, GREEN);
      }
    }
  }

  if (showMessageBox) {
    static float msg_box_width = 350.0 / 2.0;
    static float msg_box_height = 150.0 / 2.0;

    int btnActive = -1;
    const char *winner =
        game_won_by == 1 ? "Game won by White" : "Game won by Green";
    GuiMessageBox((Rectangle){center_x - msg_box_width,
                              center_y - msg_box_height, msg_box_width * 2.0f,
                              msg_box_height * 2.0f},
                  "#191#Message Box", winner, "Restart;Close", &btnActive);

    if (btnActive >= 0)
      showMessageBox = false;
  }

  EndDrawing();
}
