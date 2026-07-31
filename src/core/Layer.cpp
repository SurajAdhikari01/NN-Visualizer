#include "core/Layer.hpp"
#include <raylib.h>

Layer::Layer() { ChangeDirectory(GetApplicationDirectory()); }
Layer::~Layer() {}

void Layer::on_attach() { InitWindow(1289, 720, "NN-VISUALIZER"); }
void Layer::on_detach() { CloseWindow(); }

void Layer::on_update() {}
void Layer::on_draw() {
  BeginDrawing();
  ClearBackgorund(WHITE);
  EndDrawing();
}
