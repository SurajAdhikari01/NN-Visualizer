#pragma once
class Layer {

public:
  Layer();
  ~Layer();
  void on_attach();
  void on_detach();
  void on_update();
  void on_draw();
};
